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

    set(TARGET_COMPILE_OPTIONS -Wall -Wextra -Werror -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL MSVC)

    set(TARGET_COMPILE_OPTIONS /Wall /WX /utf-8)
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

# Apply patches
message("Apply patches")
find_package(Git REQUIRED)

execute_process(COMMAND ${GIT_EXECUTABLE} submodule foreach --recursive git reset --hard
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

execute_process(COMMAND sh ./scripts/apply-patches.sh
    RESULT_VARIABLE APPLY_PATCHES_CODE
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

if (NOT APPLY_PATCHES_CODE EQUAL 0)
    message(FATAL_ERROR "Can't apply patches (code: ${APPLY_PATCHES_CODE})")
endif()

# 3rd-party libs
add_subdirectory(libs)

# Internal libs
add_subdirectory(src)
