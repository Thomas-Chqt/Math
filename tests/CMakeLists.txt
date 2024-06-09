# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:43:15
# ---------------------------------------------------

include(FetchContent)
include(GoogleTest)


add_executable(Math_test)

set_target_properties(Math_test PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE MATH_TEST_SRC "*.cpp" "*.tpp" "*.hpp")
target_sources(Math_test PRIVATE ${MATH_TEST_SRC})

target_include_directories(Math_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(Math_test PRIVATE Math)

set(BUILD_GMOCK OFF)
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG v1.14.0)
FetchContent_MakeAvailable(googletest)
target_link_libraries(Math_test PRIVATE GTest::gtest_main)


gtest_discover_tests(Math_test)