# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:35:16
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.16)

enable_testing()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(MATH_BUILD_TESTS  "Build Math tests"             OFF)
option(MATH_INSTALL      "Enable Math install command"  ON)

if(BUILD_SHARED_LIBS)
    set(MATH_API_EXPORT ON CACHE BOOL "Export all the symbols" FORCE)
else()
    option(MATH_API_EXPORT "Export all the symbols" OFF)
endif()

project(Math)
enable_language(CXX)

add_library(Math)

set_target_properties(Math
    PROPERTIES CXX_STANDARD 11
    CXX_STANDARD_REQUIRED   ON
    CXX_VISIBILITY_PRESET   hidden
)

file(GLOB_RECURSE MATH_SRC "src/*" "include/*")
target_sources(Math PRIVATE ${MATH_SRC})

target_include_directories(Math PRIVATE "src" PUBLIC "include")

if(MATH_API_EXPORT)
    target_compile_definitions(Math PRIVATE "MATH_API_EXPORT")
endif()
if(BUILD_SHARED_LIBS)
    target_compile_definitions(Math INTERFACE "MATH_API_IMPORT")
endif()

add_subdirectory("dependencies")

if (MATH_BUILD_TESTS AND NOT (BUILD_SHARED_LIBS AND WIN32))
    add_subdirectory(tests)
endif()

if(MATH_INSTALL)
    install(TARGETS Math
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
    )
    install(DIRECTORY "include/" DESTINATION "include")
endif()