#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;
//#define ADDDOT
#define BLOCK
//#define CHECK
#define BLOCK_SIZE (1 << 11)
int N = (1 << 12);

void gemm_verify(float *A, float *B, float *C); // you can use inline function
void gemm_avx_block(float *A, const float *B, float *C); // you can use inline function
void gemm_baseline(const float *A, const float *B, float *C);

int main() {
    // malloc A, B, C
    N = (N < 8 ? 8 : N);
    auto *A = (float *)malloc(N * N * sizeof(float));
    auto *B = (float *)malloc(N * N * sizeof(float));
    auto *C = (float *)malloc(N * N * sizeof(float));
    memset (C, 0, N * N * sizeof(float));
    
    // random initialize A, B by float
    uniform_real_distribution<double> u(-10, 10);
    default_random_engine e(time(nullptr));
    for (int i = 0; i < N * N; i++) {
        A[i] = u(e);
        B[i] = u(e);
    }
    auto start = chrono::system_clock::now();
    gemm_avx_block(A, B, C);
    auto end = chrono::system_clock::now();
    chrono::duration<double> microseconds = end - start;
    cout << "Time: " << microseconds.count() * 1000 << "ms" << endl;
#ifdef CHECK
    gemm_verify(A, B, C);
#endif
    free(A);
    free(B);
    free(C);
    return 0;
}
#ifdef CHECK
void gemm_baseline(const float *A, const float *B, float *C) {
   for (int i = 0; i < N; i++) {
       for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                C[i * N + j] += A[i * N + k] * B[k * N + j];
            }
       }
   }
}
#endif
#ifdef CHECK
void gemm_verify(float *A, float *B, float *C) {
    auto *D = (float *)malloc(N * N * sizeof(float));
    memset (D, 0, N * N * sizeof(float));
    gemm_baseline(A, B, D);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(C[i * N + j] - D[i * N + j]) / (D[i * N + j] == 0.0f ? 1e-3:D[i * N + j]) > 1e-3 
                && abs(C[i * N + j] - D[i * N + j]) > 1e-2) {
                cout << "Wrong Answer!" << endl;
                cout << "C[" << i << "][" << j << "] = " << C[i * N + j] << endl;
                cout << "D[" << i << "][" << j << "] = " << D[i * N + j] << endl;
                cout << "Error: " << abs(C[i * N + j] - D[i * N + j]) << endl;
                return;
            }
        }
    }
    cout << "Correct!" << endl;
    free(D);
}
#endif
#ifdef ADDDOT
void addDot8x8Pack(float *A, float *B, float *C, int size){
    float *bptr = B;
    __m256 sum0 = _mm256_setzero_ps();
    __m256 sum1 = _mm256_setzero_ps();
    __m256 sum2 = _mm256_setzero_ps();
    __m256 sum3 = _mm256_setzero_ps();
    __m256 sum4 = _mm256_setzero_ps();
    __m256 sum5 = _mm256_setzero_ps();
    __m256 sum6 = _mm256_setzero_ps();
    __m256 sum7 = _mm256_setzero_ps();
    for(int k = 0; k < size; k++){
        __m256 a0 = _mm256_set1_ps(A[0 * N + k]);
        __m256 a1 = _mm256_set1_ps(A[1 * N + k]);
        __m256 a2 = _mm256_set1_ps(A[2 * N + k]);
        __m256 a3 = _mm256_set1_ps(A[3 * N + k]);
        __m256 a4 = _mm256_set1_ps(A[4 * N + k]);
        __m256 a5 = _mm256_set1_ps(A[5 * N + k]);
        __m256 a6 = _mm256_set1_ps(A[6 * N + k]);
        __m256 a7 = _mm256_set1_ps(A[7 * N + k]);

        __m256 b = _mm256_loadu_ps(bptr);

        sum0 = _mm256_fmadd_ps(a0, b, sum0);
        sum1 = _mm256_fmadd_ps(a1, b, sum1);
        sum2 = _mm256_fmadd_ps(a2, b, sum2);
        sum3 = _mm256_fmadd_ps(a3, b, sum3);
        sum4 = _mm256_fmadd_ps(a4, b, sum4);
        sum5 = _mm256_fmadd_ps(a5, b, sum5);
        sum6 = _mm256_fmadd_ps(a6, b, sum6);
        sum7 = _mm256_fmadd_ps(a7, b, sum7);

        bptr += 8;
    }
    _mm256_storeu_ps(&C[0 * N], sum0);
    _mm256_storeu_ps(&C[1 * N], sum1);
    _mm256_storeu_ps(&C[2 * N], sum2);
    _mm256_storeu_ps(&C[3 * N], sum3);
    _mm256_storeu_ps(&C[4 * N], sum4);
    _mm256_storeu_ps(&C[5 * N], sum5);
    _mm256_storeu_ps(&C[6 * N], sum6);
    _mm256_storeu_ps(&C[7 * N], sum7);
}
#endif
void mul_block(const float*A, const float*B, float *C, int size){
    // 把每个快再分成8*8的小块
    __m256 ci0j, ci1j, ci2j, ci3j, ci4j, ci5j, ci6j, ci7j;
    for(int j = 0; j < size; j += 8){
        for(int i = 0; i < size; i += 8){
            ci0j = _mm256_loadu_ps(&C[(i + 0) * N + j]);
            ci1j = _mm256_loadu_ps(&C[(i + 1) * N + j]);
            ci2j = _mm256_loadu_ps(&C[(i + 2) * N + j]);
            ci3j = _mm256_loadu_ps(&C[(i + 3) * N + j]);
            ci4j = _mm256_loadu_ps(&C[(i + 4) * N + j]);
            ci5j = _mm256_loadu_ps(&C[(i + 5) * N + j]);
            ci6j = _mm256_loadu_ps(&C[(i + 6) * N + j]);
            ci7j = _mm256_loadu_ps(&C[(i + 7) * N + j]);

            for(int k = 0; k < size; k++){
                __m256 ai0k = _mm256_set1_ps(A[i * N + k]);
                __m256 ai1k = _mm256_set1_ps(A[(i + 1) * N + k]);
                __m256 ai2k = _mm256_set1_ps(A[(i + 2) * N + k]);
                __m256 ai3k = _mm256_set1_ps(A[(i + 3) * N + k]);
                __m256 ai4k = _mm256_set1_ps(A[(i + 4) * N + k]);
                __m256 ai5k = _mm256_set1_ps(A[(i + 5) * N + k]);
                __m256 ai6k = _mm256_set1_ps(A[(i + 6) * N + k]);
                __m256 ai7k = _mm256_set1_ps(A[(i + 7) * N + k]);

                __m256 bkj = _mm256_loadu_ps(&B[k * N + j]);

                ci0j = _mm256_fmadd_ps(ai0k, bkj, ci0j);
                ci1j = _mm256_fmadd_ps(ai1k, bkj, ci1j);
                ci2j = _mm256_fmadd_ps(ai2k, bkj, ci2j);
                ci3j = _mm256_fmadd_ps(ai3k, bkj, ci3j);
                ci4j = _mm256_fmadd_ps(ai4k, bkj, ci4j);
                ci5j = _mm256_fmadd_ps(ai5k, bkj, ci5j);
                ci6j = _mm256_fmadd_ps(ai6k, bkj, ci6j);
                ci7j = _mm256_fmadd_ps(ai7k, bkj, ci7j);
            }
            _mm256_storeu_ps(&C[(i + 0) * N + j], ci0j);
            _mm256_storeu_ps(&C[(i + 1) * N + j], ci1j);
            _mm256_storeu_ps(&C[(i + 2) * N + j], ci2j);
            _mm256_storeu_ps(&C[(i + 3) * N + j], ci3j);
            _mm256_storeu_ps(&C[(i + 4) * N + j], ci4j);
            _mm256_storeu_ps(&C[(i + 5) * N + j], ci5j);
            _mm256_storeu_ps(&C[(i + 6) * N + j], ci6j);
            _mm256_storeu_ps(&C[(i + 7) * N + j], ci7j);

        }
    }
}
void gemm_avx_block(float *A, const float *B, float *C){
#ifdef ADDDOT
    // 8 * 8
    auto *B_copy = new float[8 * N];
    for(int j = 0; j < N; j += 8){
        for(int i = 0; i < N; i++){
            memcpy(B_copy + i * 8, B + i * N + j, 8 * sizeof(float));
        }
        for(int i = 0; i < N; i += 8){
            addDot8x8Pack(A + i * N, B_copy, C + i * N + j, N);
        }
    }
    delete [] B_copy;
#endif
#ifdef BLOCK
    int block_size = BLOCK_SIZE;
    __m256 sum, a, b;
    for(int i = 0; i < N; i += block_size){
        for(int k = 0; k < N; k += block_size){
            for(int j = 0; j < N; j += block_size){
                mul_block(A + i * N + k, B + k * N + j, C + i * N + j, block_size);
            }
        }
    }
#endif
}