# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:43:15
# ---------------------------------------------------

include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
)

add_executable(Math_test)

file(GLOB_RECURSE MATH_TEST_SRC "*.cpp" "*.tpp" "*.hpp")
target_sources(Math_test PRIVATE ${MATH_TEST_SRC})

target_include_directories(Math_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(BUILD_GMOCK OFF)
FetchContent_MakeAvailable(googletest)
target_link_libraries(Math_test Math GTest::gtest_main)

gtest_discover_tests(Math_test)