# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:35:16
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.23)

get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
    project(Math LANGUAGES CXX)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(MATH_BUILD_TESTS "Build utils cpp test executables" OFF)

add_library(Math)

file(GLOB_RECURSE MATH_SRC "src/*.cpp" "src/*.tpp" "include/*.tpp" "src/*.hpp" "include/*.hpp")
target_sources(Math PRIVATE ${MATH_SRC})

target_include_directories(Math PRIVATE "src" PUBLIC "include")

add_subdirectory(dependencies)

if (MATH_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()