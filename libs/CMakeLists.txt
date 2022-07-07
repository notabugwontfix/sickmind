# GLEW
SET(glew-cmake_BUILD_SHARED OFF CACHE INTERNAL "")
add_subdirectory(glew)

# GLFW
SET(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
add_subdirectory(glfw)

# ICU
add_subdirectory(icu)

# FreeType
SET(FT_DISABLE_HARFBUZZ ON CACHE INTERNAL "")
add_subdirectory(freetype)

# HarfBuzz
set(SKIP_INSTALL_ALL ON)
SET(HB_HAVE_ICU ON CACHE INTERNAL "")
add_subdirectory(harfbuzz)

# GLM
add_subdirectory(glm)

# doctest
add_subdirectory(doctest)
