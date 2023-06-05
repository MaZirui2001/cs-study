#include <bits/stdc++.h>
#include <cuda_runtime.h>
using namespace std;

#define TILE_WIDTH 32
// CUDA核函数：矩阵乘法
__global__ void gemm_baseline(float *A, float *B, float *C, int N)
{
    int threadId = (blockIdx.y * blockDim.y + threadIdx.y) * gridDim.x * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;
	if (threadId >= N * N){
		return;
    }
	int row = threadId / N;
	int col = threadId % N;

	C[threadId] = 0;
	for (size_t i = 0; i < N; i++){
		C[threadId] += A[row * N + i] * B[i * N + col];
	}
}
// void gemm_baseline_CPU(const float *A, const float *B, float *C) {
//    for (int i = 0; i < N; i++) {
//        for (int k = 0; k < N; k++) {
//            for (int j = 0; j < N; j++) {
//                C[i * N + j] += A[i * N + k] * B[k * N + j];
//            }
//        }
//    }
// }

void gemm_verify(float *A, float *B, float *C, int N) {
    auto *D = (float *)malloc(N * N * sizeof(float));
    memset (D, 0, N * N * sizeof(float));
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for(int j = 0; j < N; j++) {
                D[i * N + j] += A[i * N + k] * B[k * N + j];
            }
        }
    }
    for (int i = 0; i < N * N; i++) {
        if (abs(C[i] - D[i]) > 1e-1 && abs(C[i] - D[i] / D[i]) > 1e-2) {
            cout << "Wrong!" << endl;
            return;
        }
    }
    cout << "Correct!" << endl;
    free(D);
}

int main()
{
    int N = 1 << 10; // 矩阵宽度
    int size = N * N * sizeof(float);

    // 分配主机内存
    float *h_A = (float *)malloc(size);
    float *h_B = (float *)malloc(size);
    float *h_C = (float *)malloc(size);
    uniform_real_distribution<double> u(-10, 10);
    default_random_engine e(time(nullptr));
    // 初始化矩阵
    for (int i = 0; i < N * N; i++) {
        h_A[i] = u(e);
        h_B[i] = u(e);
        h_C[i] = 0.0f;
    }

    // 分配设备内存
    float *d_A, *d_B, *d_C;
    cudaMalloc((void **)&d_A, size);
    cudaMalloc((void **)&d_B, size);
    cudaMalloc((void **)&d_C, size);

    // 将主机内存数据复制到设备内存
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // 定义CUDA核函数的块大小和线程大小
    dim3 blockDim(TILE_WIDTH, TILE_WIDTH);
    dim3 gridDim((N + TILE_WIDTH - 1) / TILE_WIDTH, (N + TILE_WIDTH - 1) / TILE_WIDTH);

    // 调用CUDA核函数
    // 高精度计时
    auto start = chrono::system_clock::now();
    for(int i = 0; i < 10; i++)
        gemm_baseline<<<gridDim, blockDim>>>(d_A, d_B, d_C, N);
    auto end = chrono::system_clock::now();
    

    // 将设备内存数据复制到主机内存
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "elapsed time: " << duration.count() << "micros\n";

    // 验证结果
    gemm_verify(h_A, h_B, h_C, N);

    // 释放内存
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    free(h_A);
    free(h_B);
    free(h_C);

    return 0;
}