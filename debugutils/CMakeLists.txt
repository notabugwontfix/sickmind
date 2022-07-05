cmake_minimum_required(VERSION 3.22)
project(debugutils)

# Main target
add_library(${PROJECT_NAME} src/Log.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest)

# Compiler settings
set_target_properties(${PROJECT_NAME} PROPERTIES ${TARGET_PROPERTIES})
target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
