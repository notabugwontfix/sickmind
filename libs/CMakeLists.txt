# Apply patches
message("Apply patches")
find_package(Git REQUIRED)

execute_process(COMMAND sh ./scripts/apply-patches.sh
    RESULT_VARIABLE APPLY_PATCHES_CODE
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

if (NOT APPLY_PATCHES_CODE EQUAL 0)
    message(FATAL_ERROR "Can't apply patches (code: ${APPLY_PATCHES_CODE})")
endif()

# GLEW
SET(glew-cmake_BUILD_SHARED OFF CACHE INTERNAL "" FORCE)
add_subdirectory(glew)

# GLFW
SET(GLFW_BUILD_DOCS OFF CACHE INTERNAL "" FORCE)
add_subdirectory(glfw)

# ICU
add_subdirectory(icu)

# FreeType
SET(FT_DISABLE_HARFBUZZ ON CACHE INTERNAL "" FORCE)
add_subdirectory(freetype)

# HarfBuzz
set(SKIP_INSTALL_ALL ON)
SET(HB_HAVE_ICU ON CACHE INTERNAL "" FORCE)
add_subdirectory(harfbuzz)

# GLM
add_subdirectory(glm)

# doctest
add_subdirectory(doctest)
