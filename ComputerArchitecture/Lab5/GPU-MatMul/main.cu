#include <iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <random>
using namespace std;
// Device Name : NVIDIA GeForce GTX 1650 Ti
// totalGlobalMem : 4294705152
// sharedMemPerBlock 49152
// regsPerBlock : 65536
// warpSize : 32
// memPitch : 2147483647
// maxThreadsPerBlock 1024
// maxThreadsDim[0 - 2] : 1024 1024 64
// maxGridSize[0 - 2] 2147483647 65535 65535
// totalConstMem : 65536
// major.minor : 7.5
// clockRate : 1485000
// textureAlignment : 512
// deviceOverlap : 1
// multiProcessorCount : 16

void printDeviceProp(const cudaDeviceProp& prop)
{
    cout << "Device Name : " << prop.name << "\n";
    cout << "totalGlobalMem : " << prop.totalGlobalMem << "\n";
    cout << "sharedMemPerBlock " << prop.sharedMemPerBlock << "\n";
    cout << "regsPerBlock : " << prop.regsPerBlock << "\n";
    cout << "warpSize :" << prop.warpSize << "\n";
    cout << "memPitch : " << prop.memPitch << "\n";
    cout << "maxThreadsPerBlock " << prop.maxThreadsPerBlock << "\n";
    cout << "maxThreadsDim[0 - 2] : " << prop.maxThreadsDim[0] << " " << prop.maxThreadsDim[1] << " " << prop.maxThreadsDim[2] << "\n";
    cout << "maxGridSize[0 - 2] " << prop.maxGridSize[0] << " " << prop.maxGridSize[1] << " " << prop.maxGridSize[2] << "\n";
    cout << "totalConstMem : " << prop.totalConstMem << "\n";
    cout << "major.minor : " << prop.major << "." << prop.minor << "\n";
    cout << "clockRate : " << prop.clockRate << "\n";
    cout << "textureAlignment :" << prop.textureAlignment << "\n";
    cout << "deviceOverlap : " << prop.deviceOverlap << "\n";
    cout << "multiProcessorCount : " << prop.multiProcessorCount << "\n";
}
int main() {
    cudaDeviceProp prop{};
    cudaGetDeviceProperties(&prop, 0);
    printDeviceProp(prop);
    return 0;
}
