# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:35:16
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.16)

option(BUILD_SHARED_LIBS  "Build using shared libraries"       OFF)
option(MATH_INCLUDE_TESTS "Include Math tests int the project" OFF)

project(Math CXX)

add_subdirectory("dependencies")

add_library(Math)

set_target_properties(Math PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE MATH_SRC "src/*.cpp" "src/*.tpp" "include/*.tpp" "src/*.hpp" "include/*.hpp")
target_sources(Math PRIVATE ${MATH_SRC})

target_include_directories(Math PRIVATE "src" PUBLIC "include")


target_link_libraries(Math PUBLIC UtilsCPP)


if (MATH_INCLUDE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()