# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:43:15
# ---------------------------------------------------

include(FetchContent)
include(GoogleTest)


add_executable(Math_test)

set_target_properties(Math_test
    PROPERTIES CXX_STANDARD 14
    CXX_STANDARD_REQUIRED   ON
    FOLDER                  "tests"
)

file(GLOB_RECURSE MATH_TEST_SRC "*.cpp" "*.tpp" "*.hpp")
target_sources(Math_test PRIVATE ${MATH_TEST_SRC})

target_include_directories(Math_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(BUILD_SHARED_LIBS_BACK ${BUILD_SHARED_LIBS})
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build using shared libraries" FORCE)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
    GIT_SHALLOW    1
)
set(BUILD_GMOCK   OFF)
set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)
set_target_properties(gtest PROPERTIES FOLDER "dependencies")
set_target_properties(gtest_main PROPERTIES FOLDER "dependencies")
set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS_BACK} CACHE BOOL "Build using shared libraries" FORCE)

target_link_libraries(Math_test PRIVATE Math GTest::gtest_main)

gtest_discover_tests(Math_test)