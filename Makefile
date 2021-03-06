SICKMIND_CC ?= clang
SICKMIND_CXX ?= clang++
SICKMIND_GENERATOR ?= Ninja
SICKMIND_BUILD_TYPE ?= Debug
SICKMIND_BUILD_TESTS ?= OFF

export CC = $(SICKMIND_CC)
export CXX = $(SICKMIND_CXX)

BUILD_DIR = "build/$(SICKMIND_BUILD_TYPE)"

.PHONY: configure
configure:
	cmake -S . -B $(BUILD_DIR) -G "$(SICKMIND_GENERATOR)" \
		-D CMAKE_BUILD_TYPE="$(SICKMIND_BUILD_TYPE)" \
		-D CMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-D SICKMIND_BUILD_TESTS="$(SICKMIND_BUILD_TESTS)"

.PHONY: build
build: configure
	cmake --build $(BUILD_DIR) --config "$(SICKMIND_BUILD_TYPE)" --parallel

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: run
run: build
	./$(BUILD_DIR)/install/sickmind

.PHONY: test
test: SICKMIND_BUILD_TESTS = ON
test: build
	ctest --output-on-failure --test-dir $(BUILD_DIR) -C "$(SICKMIND_BUILD_TYPE)"

.PHONY: patches
patches:
	- ./scripts/apply-patches.sh
	./scripts/make-patches.sh

.PHONY: submodules
submodules:
	git submodule update --init --recursive --jobs 4
	git pull --recurse-submodules --jobs 4

.PHONY: update-submodules
update-submodules: reset-submodules
	git submodule foreach git pull

.PHONY: reset-submodules
reset-submodules:
	git submodule foreach --recursive git reset --hard

.PHONY: clang-format
clang-format:
	git ls-files -- '*.cpp' '*.h' | xargs clang-format -i -style=file
	git diff --exit-code --color
