cmake_minimum_required(VERSION 3.22)
project(app)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE debugutils

    PRIVATE glfw
    PRIVATE libglew_static
    PRIVATE glm

    PRIVATE doctest
    PRIVATE freetype
    PRIVATE harfbuzz-icu
)

# Rename executable
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "sickmind")
