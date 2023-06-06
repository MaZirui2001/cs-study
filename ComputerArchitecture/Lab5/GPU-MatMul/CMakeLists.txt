cmake_minimum_required(VERSION 3.25)
project(GPU CUDA)

set(CMAKE_CUDA_STANDARD 17)
find_package(CUDA REQUIRED)


add_executable(GPU
        main.cu)
add_executable(Baseline
        MatMul-Baseline.cu)
add_executable(Shared
        MatMul-Block.cu)

set_target_properties(GPU PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
