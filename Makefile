CC = clang
CXX = clang++

BUILD_TYPE = Release
BUILD_TESTS = OFF

.PHONY: configure
configure:
	CC=$(CC) CXX=$(CXX) cmake -S . -B build -G Ninja \
		-D CMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		-D CMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-D SICKMIND_BUILD_TESTS=$(BUILD_TESTS)

.PHONY: build
build: configure
	cmake --build build --config $(BUILD_TYPE) --parallel

.PHONY: clean
clean:
	git submodule foreach --recursive git reset --hard
	rm -rf build

.PHONY: run
run: build
	./build/install/sickmind

.PHONY: test
test: BUILD_TESTS = ON
test: build
	./build/install/sickmind

.PHONY: submodules
submodules:
	git submodule update --init --recursive
	git pull --recurse-submodules --jobs=8
