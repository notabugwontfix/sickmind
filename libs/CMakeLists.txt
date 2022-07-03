# GLEW
option(glew-cmake_BUILD_SHARED "Build shared glew library" OFF)
set(glew-cmake_BUILD_SHARED OFF)
option(glew-cmake_BUILD_MULTI_CONTEXT "Build the multi-context glew library" OFF)
set(glew-cmake_BUILD_MULTI_CONTEXT OFF)
add_subdirectory(glew)

# GLFW
option(GLFW_BUILD_DOCS "Build docs" OFF)
set(GLFW_BUILD_DOCS OFF)
add_subdirectory(glfw)

# Other libs
add_subdirectory(glm)
