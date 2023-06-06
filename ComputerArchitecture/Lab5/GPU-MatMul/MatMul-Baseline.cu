#include <iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <random>
#include <cstdint>
using namespace std;

//#define CHECK
#define TILE_WIDTH 32
// CUDA核函数：矩阵乘法
__global__ void gemm_baseline(const float* A, const float* B, float* C, int N)
{
    uint32_t threadId = (blockIdx.y * blockDim.y + threadIdx.y) * gridDim.x * blockDim.x + blockIdx.x * blockDim.x + threadIdx.x;
    if (threadId >= N * N) {
        return;
    }
    uint32_t row = threadId / N;
    uint32_t col = threadId % N;

    C[threadId] = 0;
    for (size_t i = 0; i < N; i++) {
        C[threadId] += A[row * N + i] * B[i * N + col];
    }
}
#ifdef CHECK
void gemm_verify(const float* A, const float* B, float* C, int N) {
    auto* D = (float*)malloc(N * N * sizeof(float));
    memset(D, 0, N * N * sizeof(float));

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
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
#endif
int main()
{
    uint32_t N = 1 << 10; // 矩阵宽度
    uint32_t size = N * N * sizeof(float);

    // 分配主机内存
    auto* h_A = (float*)malloc(size);
    auto* h_B = (float*)malloc(size);
    auto* h_C = (float*)malloc(size);
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    uniform_real_distribution<double> u(-10, 10);
    default_random_engine e(time(nullptr));
    // 初始化矩阵
    for (int i = 0; i < N * N; i++) {
        h_A[i] = (float)u(e);
        h_B[i] = (float)u(e);
        h_C[i] = 0.0f;
    }
    // 分配设备内存
    float* d_A, * d_B, * d_C;
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMalloc((void**)&d_C, size);

    // 将主机内存数据复制到设备内存
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // 定义CUDA核函数的块大小和线程大小
    dim3 block_dim(TILE_WIDTH, TILE_WIDTH);
    dim3 grid_dim((N + TILE_WIDTH - 1) / TILE_WIDTH, (N + TILE_WIDTH - 1) / TILE_WIDTH);

    // 调用CUDA核函数
    // 高精度计时
    cudaEventRecord(start, nullptr);
    gemm_baseline <<<grid_dim, block_dim >>> (d_A, d_B, d_C, N);
    cudaEventRecord(stop, nullptr);
    cudaEventSynchronize(stop);

    // 将设备内存数据复制到主机内存
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
    float duration;
    cudaEventElapsedTime(&duration, start, stop);
    cout << "elapsed time: " << duration << "micros\n";

    // 验证结果
#ifdef CHECK
    gemm_verify(h_A, h_B, h_C, N);
#endif

    // 释放内存
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    free(h_A);
    free(h_B);
    free(h_C);

    return 0;
}