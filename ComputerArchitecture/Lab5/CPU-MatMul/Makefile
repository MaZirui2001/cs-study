default: avx
CPU_DIR =  .
BUILD_DIR = $(CPU_DIR)/build
GCC = g++
CPP_FLAGS = -mavx2 -march=haswell -O2 -std=c++11 -g
BIN = $(BUILD_DIR)/MatMul-$(TYPE)
baseline:
	@mkdir -p $(BUILD_DIR)
	@$(GCC)  $(CPU_DIR)/MatMul-Baseline.cpp -S $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-Baseline.s
	@$(GCC)  $(CPU_DIR)/MatMul-Baseline.cpp $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-baseline
avx:
	@mkdir -p $(BUILD_DIR)
	@$(GCC)  $(CPU_DIR)/MatMul-AVX.cpp -S $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-AVX.s
	@$(GCC)  $(CPU_DIR)/MatMul-AVX.cpp $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-avx
avxblock:
	@mkdir -p $(BUILD_DIR)
	@$(GCC)  $(CPU_DIR)/MatMul-AVXBlock.cpp -S $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-AVXBlock.s
	@$(GCC)  $(CPU_DIR)/MatMul-AVXBlock.cpp $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-avxblock
run: $(TYPE)
	@$(BIN)
clean:
	@rm -rf $(BUILD_DIR)