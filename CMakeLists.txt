cmake_minimum_required(VERSION 3.22)
project(sickmind)

# Install directory
set(INSTALL_DIR ${CMAKE_BINARY_DIR}/install)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${INSTALL_DIR})

# Global target compile options
if (CMAKE_CXX_COMPILER_ID STREQUAL GNU OR
    CMAKE_CXX_COMPILER_ID STREQUAL Clang OR
    CMAKE_CXX_COMPILER_ID STREQUAL AppleClang)

    set(TARGET_COMPILE_OPTIONS -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL MSVC)

    set(TARGET_COMPILE_OPTIONS /Wall /WX)
endif()

# Global target properties
set(TARGET_PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

# Testing
option(SICKMIND_BUILD_TESTS "sickmind: Build tests" OFF)
if(SICKMIND_BUILD_TESTS)
    enable_testing()
    add_test(NAME sickmind-test COMMAND sickmind)
else()
    add_compile_definitions(DOCTEST_CONFIG_DISABLE)
endif()

# 3rd-party libs
add_subdirectory(libs)

# Internal libs
add_subdirectory(src)
