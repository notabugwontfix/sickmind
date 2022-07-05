cmake_minimum_required(VERSION 3.22)
project(sickmind)

# Main target
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE debugutils

    PRIVATE glfw
    PRIVATE libglew_static
    PRIVATE glm

    PRIVATE doctest
)

set_target_properties(${PROJECT_NAME} PROPERTIES ${TARGET_PROPERTIES})
target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
