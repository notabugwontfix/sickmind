SICKMIND_CC ?= clang
SICKMIND_CXX ?= clang++
SICKMIND_GENERATOR ?= Ninja
SICKMIND_BUILD_TYPE ?= Release
SICKMIND_BUILD_TESTS ?= OFF

export CC = $(SICKMIND_CC)
export CXX = $(SICKMIND_CXX)

.PHONY: configure
configure:
	cmake -S . -B build -G "$(SICKMIND_GENERATOR)" \
		-D CMAKE_BUILD_TYPE=$(SICKMIND_BUILD_TYPE) \
		-D CMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-D SICKMIND_BUILD_TESTS=$(SICKMIND_BUILD_TESTS)

.PHONY: build
build: configure
	cmake --build build --config $(SICKMIND_BUILD_TYPE) --parallel

.PHONY: clean
clean:
	git submodule foreach --recursive git reset --hard
	rm -rf build

.PHONY: run
run: build
	./build/install/sickmind

.PHONY: test
test: SICKMIND_BUILD_TESTS = ON
test: build
	./build/install/sickmind

.PHONY: submodules
submodules:
	git submodule update --init --recursive --jobs 4
	git pull --recurse-submodules --jobs 4
