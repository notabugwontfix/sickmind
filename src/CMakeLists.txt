set(TARGETS
    debugutils

    app
)

foreach(TARGET ${TARGETS})
    add_subdirectory(${TARGET})

    # Target compile options
    if (CMAKE_CXX_COMPILER_ID STREQUAL GNU OR
        CMAKE_CXX_COMPILER_ID STREQUAL Clang OR
        CMAKE_CXX_COMPILER_ID STREQUAL AppleClang)

        set(TARGET_COMPILE_OPTIONS -Wall -Wextra -Werror)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL MSVC)

        set(TARGET_COMPILE_OPTIONS /Wall /WX)
    endif()

    # Target properties
    set(TARGET_PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
    )

    set_target_properties(${TARGET} PROPERTIES ${TARGET_PROPERTIES})
    target_compile_options(${TARGET} PRIVATE ${TARGET_COMPILE_OPTIONS})
endforeach()
