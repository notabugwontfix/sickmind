cmake_minimum_required(VERSION 3.22)
project(debugutils)

add_library(${PROJECT_NAME}
    include/debug/Assert.h
    include/debug/Trace.h
    include/debug/Stopwatch.h

    src/Trace.cpp
    src/Stopwatch.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest)
