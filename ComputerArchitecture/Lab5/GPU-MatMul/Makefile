default: baseline
GPU_DIR =  .
BUILD_DIR = $(GPU_DIR)/build
GCC = nvcc
CPP_FLAGS =
BIN = $(BUILD_DIR)/MatMul-$(TYPE)
baseline:
	@mkdir -p $(BUILD_DIR)
# @$(GCC)  $(GPU_DIR)/MatMul-Baseline.cu -S $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-Baseline.s
	@$(GCC)  $(GPU_DIR)/MatMul-Baseline.cu $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-baseline
block:
	@mkdir -p $(BUILD_DIR)
# @$(GCC)  $(GPU_DIR)/MatMul-AVX.cu -S $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-AVX.s
	@$(GCC)  $(GPU_DIR)/MatMul-Block.cu $(CPP_FLAGS) -o $(BUILD_DIR)/MatMul-block
run: $(TYPE)
	@$(BIN)
clean:
	@rm -rf $(BUILD_DIR)