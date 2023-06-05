cmake_minimum_required(VERSION 3.25)
project(Lab5)

set(CMAKE_CXX_STANDARD 14)
find_package(CUDA  REQUIRED)
include_directories("${CUDA_INCLUDE_DIRS}")

add_compile_options(-mavx2 -march=haswell -O2)
add_executable(Lab5-avx
        CPU-MatMul/MatMul-AVX.cpp)

add_executable(Lab5-baseline
        CPU-MatMul/MatMul-Baseline.cpp)

add_executable(Lab5-avxblock
        CPU-MatMul/MatMul-AVXblock.cpp)

add_executable(Lab5-GPU-baseline
        GPU-MatMul/MatMul-Baseline.cpp)
