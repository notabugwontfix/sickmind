# GLEW
SET(glew-cmake_BUILD_SHARED OFF CACHE INTERNAL "")
add_subdirectory(glew)

# GLFW
SET(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
add_subdirectory(glfw)

# FreeType
SET(FT_DISABLE_HARFBUZZ ON CACHE INTERNAL "")
add_subdirectory(freetype)

# HarfBuzz
add_subdirectory(harfbuzz)

# GLM
add_subdirectory(glm)

# doctest
add_subdirectory(doctest)
