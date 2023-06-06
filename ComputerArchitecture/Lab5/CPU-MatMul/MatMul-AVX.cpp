#include <bits/stdc++.h>
#include <immintrin.h>
#include <iostream>
#include <random>

using namespace std;
//#define VEC_VEC
#define NUM_VEC
//#define CHECK
int N = (1 << 3);

void gemm_verify(float *A, float *B, float *C); // you can use inline function
void gemm_avx(float *A, float *B, float *C); // you can use inline function
void gemm_baseline(const float *A, const float *B, float *C);

int main() {
    // malloc A, B, C
    N = (N < 8 ? 8 : N);
    auto *A = (float *) malloc(N * N * sizeof(float));
    auto *B = (float *) malloc(N * N * sizeof(float));
    auto *C = (float *) malloc(N * N * sizeof(float));
    memset(C, 0, N * N * sizeof(float));
    // random initialize A, B by float
    uniform_real_distribution<double> u(-1, 1);
    default_random_engine e(time(nullptr));
    for (int i = 0; i < N * N; i++) {
        A[i] = u(e);
        B[i] = u(e);
    }
    // measure time by chrono, measuer by ms
    auto start = chrono::system_clock::now();
    gemm_avx(A, B, C);
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
# ifdef CHECK
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
# ifdef CHECK
void gemm_verify(float *A, float *B, float *C) {
    auto *D = (float *) malloc(N * N * sizeof(float));
    memset(D, 0, N * N * sizeof(float));
    // check time
    auto start = chrono::system_clock::now();
    gemm_baseline(A, B, D);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(C[i * N + j] - D[i * N + j]) / (D[i * N + j] == 0.0f ? 1e-3 : D[i * N + j]) > 1e-3
                && abs(C[i * N + j] - D[i * N + j]) > 1e-3) {
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
// AVX version
void gemm_avx(float *A, float *B, float *C) {
#ifdef VEC_VEC
    auto *B_copy = (float *) malloc(N * N * sizeof(float));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B_copy[i * N + j] = B[j * N + i];
        }
    }
    __m256 sum, a, b, prod;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = _mm256_setzero_ps();
            for (int k = 0; k < N; k += 8) {
                a = _mm256_loadu_ps(&A[i * N + k]);
                b = _mm256_loadu_ps(&B_copy[j * N + k]);
                // prod = _mm256_dp_ps(a, b, 0xFF);
                // sum = _mm256_add_ps(sum, prod);
                sum = _mm256_fmadd_ps(a, b, sum);
            }
            C[i * N + j] = sum[0] + sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6] + sum[7];
            // C[i * N + j] = sum[0] + sum[4];
        }
    }
    free(B_copy);
#endif
#ifdef NUM_VEC
    __m256 sum, a, b;
    __m256 sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
    __m256 a0, a1, a2, a3, a4, a5, a6, a7;
    for(int k = 0; k < N; k += 8){
        for(int i = 0; i < N; i += 8){
            sum0 = _mm256_setzero_ps();
            sum1 = _mm256_setzero_ps();
            sum2 = _mm256_setzero_ps();
            sum3 = _mm256_setzero_ps();
            sum4 = _mm256_setzero_ps();
            sum5 = _mm256_setzero_ps();
            sum6 = _mm256_setzero_ps();
            sum7 = _mm256_setzero_ps();
            for(int j = 0; j < N; j++){
                a0 = _mm256_set1_ps(A[(i + 0) * N + j]);
                a1 = _mm256_set1_ps(A[(i + 1) * N + j]);
                a2 = _mm256_set1_ps(A[(i + 2) * N + j]);
                a3 = _mm256_set1_ps(A[(i + 3) * N + j]);
                a4 = _mm256_set1_ps(A[(i + 4) * N + j]);
                a5 = _mm256_set1_ps(A[(i + 5) * N + j]);
                a6 = _mm256_set1_ps(A[(i + 6) * N + j]);
                a7 = _mm256_set1_ps(A[(i + 7) * N + j]);

                b = _mm256_loadu_ps(&B[j * N + k]);

                sum0 = _mm256_fmadd_ps(a0, b, sum0);
                sum1 = _mm256_fmadd_ps(a1, b, sum1);
                sum2 = _mm256_fmadd_ps(a2, b, sum2);
                sum3 = _mm256_fmadd_ps(a3, b, sum3);
                sum4 = _mm256_fmadd_ps(a4, b, sum4);
                sum5 = _mm256_fmadd_ps(a5, b, sum5);
                sum6 = _mm256_fmadd_ps(a6, b, sum6);
                sum7 = _mm256_fmadd_ps(a7, b, sum7);
            }
            _mm256_storeu_ps(&C[(i + 0) * N + k], sum0);
            _mm256_storeu_ps(&C[(i + 1) * N + k], sum1);
            _mm256_storeu_ps(&C[(i + 2) * N + k], sum2);
            _mm256_storeu_ps(&C[(i + 3) * N + k], sum3);
            _mm256_storeu_ps(&C[(i + 4) * N + k], sum4);
            _mm256_storeu_ps(&C[(i + 5) * N + k], sum5);
            _mm256_storeu_ps(&C[(i + 6) * N + k], sum6);
            _mm256_storeu_ps(&C[(i + 7) * N + k], sum7);
        }
    }
#endif
}