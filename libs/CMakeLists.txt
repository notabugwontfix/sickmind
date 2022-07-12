# Apply patches
message("Apply patches")
find_package(Git REQUIRED)

execute_process(COMMAND sh ./scripts/apply-patches.sh
    RESULT_VARIABLE APPLY_PATCHES_CODE
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

if(NOT APPLY_PATCHES_CODE EQUAL 0)
    message(FATAL_ERROR "Can't apply patches (code: ${APPLY_PATCHES_CODE})")
endif()

# GLEW
set(glew-cmake_BUILD_SHARED OFF CACHE INTERNAL "" FORCE)
set(ONLY_LIBS ON CACHE INTERNAL "" FORCE)
add_subdirectory(glew)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "" FORCE)
add_subdirectory(glfw)

# ICU
add_subdirectory(icu)

# FreeType
set(SKIP_INSTALL_ALL ON)
set(FT_DISABLE_ZLIB ON CACHE INTERNAL "" FORCE)
set(FT_DISABLE_BZIP2 ON CACHE INTERNAL "" FORCE)
set(FT_DISABLE_PNG ON CACHE INTERNAL "" FORCE)
set(FT_DISABLE_HARFBUZZ ON CACHE INTERNAL "" FORCE)
set(FT_DISABLE_BROTLI ON CACHE INTERNAL "" FORCE)
add_subdirectory(freetype)

# HarfBuzz
set(HB_HAVE_ICU ON CACHE INTERNAL "" FORCE)
add_subdirectory(harfbuzz)

# GLM
add_subdirectory(glm)

# doctest
set(DOCTEST_NO_INSTALL ON CACHE INTERNAL "" FORCE)
add_subdirectory(doctest)
