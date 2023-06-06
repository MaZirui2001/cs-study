#include <bits/stdc++.h>
using namespace std;

int N = (1 << 11);

void gemm_baseline(const float *A, const float *B, float *C); // you can use inline function

int main() {

   // malloc A, B, C
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
   gemm_baseline(A, B, C);
   auto end = chrono::system_clock::now();
   chrono::duration<double> microseconds = end - start;
   cout << "Time: " << microseconds.count() * 1000 << "ms" << endl;
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