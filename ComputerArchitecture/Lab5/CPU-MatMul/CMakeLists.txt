cmake_minimum_required(VERSION 3.25)
project(CPU)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("-mavx2" "-march=haswell")
add_executable(AVX
        MatMul-AVX.cpp)
add_executable(Block
        MatMul-AVXblock.cpp)
add_executable(Baseline
        MatMul-Baseline.cpp)
#add_executable(Lab5GPU-Baseline
#        GPU-MatMul/MatMul-Baseline.cu)
#add_executable(Lab5GPU-Block
#        GPU-MatMul/MatMul-Block.cu)
