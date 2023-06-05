#include <bits/stdc++.h>
#include <immintrin.h>

using namespace std;
#define VEC_VEC
// #define NUM_VEC
#define CHECK
int N = (1 << 10);

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
    __m256 sum, a, b, c;
    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k += 8){
            sum = _mm256_setzero_ps();
            for(int j = 0; j < N; j++){
                a = _mm256_set1_ps(A[i * N + j]);
                b = _mm256_loadu_ps(&B[j * N + k]);
                sum = _mm256_fmadd_ps(a, b, sum);
            }
            _mm256_storeu_ps(&C[i * N + k], sum);
        }
    }
#endif
}