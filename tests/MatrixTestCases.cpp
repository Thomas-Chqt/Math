/*
 * ---------------------------------------------------
 * MatrixTestCases.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/06/15 11:33:46
 * ---------------------------------------------------
 */

#include <gtest/gtest.h>
#include "Math/Matrix.hpp"
#include "Math/Vector.hpp"
#include "Math/Constants.hpp"

using namespace math;

namespace math_test
{

TEST(MatrixTest, equal)
{
    math::mat3x3 mat1 = { 4, 3, 6,
                          6, 1, 4,
                          9, 8, 16 };

    EXPECT_EQ(mat1, mat1);
}

TEST(MatrixTest, multiplication)
{
    math::mat3x3 mat1 = { 4, 3, 6,
                          6, 1, 4,
                          9, 8, 16 };

    math::mat3x3 mat2 = { 1, 0, 0,
                          0, 1, 0,
                          0, 0, 1 };

    math::mat3x3 mat3 = {  88,  63, 132,
                           66,  51, 104,
                          228, 163, 342 };

    EXPECT_EQ(mat1 * mat1, mat3);
    EXPECT_EQ(mat2 * mat1, mat1);
}

TEST(MatrixTest, sizeof)
{
    EXPECT_EQ(sizeof(mat4x4), 64);
    EXPECT_EQ(sizeof(mat3x3), 48);
}

TEST(MatrixTest, alignof)
{
    EXPECT_EQ(alignof(mat4x4), 16);
    EXPECT_EQ(alignof(mat3x3), 16);
}

TEST(MatrixTest, rotation)
{
    {
        vec3f originalVec = vec3f(1, 0, 0);
        vec3f rotatedVec  = (mat4x4::rotation({0, PI / 2, 0}) * vec4f(originalVec, 1)).xyz();
        vec3f expectedVec = vec3f(0, 0, -1);

        EXPECT_NEAR(rotatedVec.x, expectedVec.x, 0.0001);
        EXPECT_NEAR(rotatedVec.y, expectedVec.y, 0.0001);
        EXPECT_NEAR(rotatedVec.z, expectedVec.z, 0.0001);
    }
    {
        vec3f originalVec = vec3f(0, 1, 0);
        vec3f rotatedVec  = (mat4x4::rotation({0, 0, PI / 2}) * vec4f(originalVec, 1)).xyz();
        vec3f expectedVec = vec3f(-1, 0, 0);

        EXPECT_NEAR(rotatedVec.x, expectedVec.x, 0.0001);
        EXPECT_NEAR(rotatedVec.y, expectedVec.y, 0.0001);
        EXPECT_NEAR(rotatedVec.z, expectedVec.z, 0.0001);
    }
    {
        vec3f originalVec = vec3f(0, 0, 1);
        vec3f rotatedVec  = (mat4x4::rotation({PI / 2, 0, 0}) * vec4f(originalVec, 1)).xyz();
        vec3f expectedVec = vec3f(0, -1, 0);

        EXPECT_NEAR(rotatedVec.x, expectedVec.x, 0.0001);
        EXPECT_NEAR(rotatedVec.y, expectedVec.y, 0.0001);
        EXPECT_NEAR(rotatedVec.z, expectedVec.z, 0.0001);
    }
}

}