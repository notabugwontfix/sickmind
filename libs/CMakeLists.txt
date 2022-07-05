# GLEW
SET(glew-cmake_BUILD_SHARED OFF CACHE INTERNAL "")
add_subdirectory(glew)

# GLFW
SET(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
add_subdirectory(glfw)

# Other libs
add_subdirectory(glm)
add_subdirectory(doctest)
