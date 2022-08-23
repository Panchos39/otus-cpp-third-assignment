cmake_minimum_required(VERSION 3.10.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(custom_memory_allocator VERSION ${PROJECT_VERSION})

include_directories(src)
include_directories(include)

add_executable(custom_memory_allocator main.cpp)


set_target_properties(custom_memory_allocator PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

target_include_directories(custom_memory_allocator
        PRIVATE "${CMAKE_BINARY_DIR}"
        )

if (MSVC)
    target_compile_options(custom_memory_allocator PRIVATE
            /W4
            )
else ()
    target_compile_options(custom_memory_allocator PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()

install(TARGETS custom_memory_allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)