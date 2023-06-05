#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;
//#define ADDDOT
#define BLOCK
#define CHECK
int N = (1 << 10);

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
    // measure time by chrono, measuer by ms
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
void gemm_baseline(const float *A, const float *B, float *C) {
   for (int i = 0; i < N; i++) {
       for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                C[i * N + j] += A[i * N + k] * B[k * N + j];
            }
       }
   }
}
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
    for(int k = 0; k < N; k++){
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
void gemm_avx_block(float *A, const float *B, float *C){
#ifdef ADDDOT
    // 8 * 8
    auto *B_copy = new float[8 * N];
    for(int j = 0; j < N; j += 8){
        for(int i = 0; i < N; i++){
            memcpy(B_copy + i * 8, B + i * N + j, 8 * sizeof(float));
        }
        for(int i = 0; i < N; i += 8){
            addDot8x8Pack(A + i * N, B_copy, C + i * N + j, 8);
        }
    }
    delete [] B_copy;
#endif
#ifdef BLOCK
    auto *B_copy = (float *) malloc(N * N * sizeof(float));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B_copy[i * N + j] = B[j * N + i];
        }
    }
    int block_size = 128;
    __m256 sum, a, b;
    for(int i = 0; i < N; i += block_size){
        for(int j = 0; j < N; j += block_size){
            for(int k = 0; k < N; k += block_size){
                for(int ii = i; ii < i + block_size; ii++){
                    for(int jj = j; jj < j + block_size; jj++){
                        sum = _mm256_setzero_ps();
                        for(int kk = k; kk < k + block_size; kk += 8){
                            a = _mm256_loadu_ps(A + ii * N + kk);
                            b = _mm256_loadu_ps(B_copy + jj * N + kk);
                            sum = _mm256_fmadd_ps(a, b, sum);
                        }
                        C[ii * N + jj] += sum[0] + sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6] + sum[7];
                    }
                }
            }
        }
    }
    free(B_copy);
#endif

}