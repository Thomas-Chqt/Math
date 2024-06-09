# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:35:16
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.16)

enable_testing()

option(BUILD_SHARED_LIBS  "Build using shared libraries"       OFF)
option(MATH_BUILD_TESTS   "Include Math tests int the project" OFF)

project(Math)

enable_language(CXX)


add_library(Math ${MATH_LIBRARY_TYPE})

set_target_properties(Math PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE MATH_SRC "src/*.cpp" "src/*.tpp" "include/*.tpp" "src/*.hpp" "include/*.hpp")
target_sources(Math PRIVATE ${MATH_SRC})

target_include_directories(Math PRIVATE "src" PUBLIC "include")

add_subdirectory("dependencies")


if (MATH_BUILD_TESTS)
    add_subdirectory(tests)
endif()