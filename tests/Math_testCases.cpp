/*
 * ---------------------------------------------------
 * Math_testCases.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 09:47:14
 * ---------------------------------------------------
 */

#include <gtest/gtest.h>
#include "Math/Vector.hpp"
#include "Math/Matrix.hpp"

namespace math_test
{

using namespace math;

TEST(VectorTest, scaling)
{
    vec3f v = { 1, 2, 3 };

    v *= 3;

    EXPECT_EQ(v.x, 1 * 3);
    EXPECT_EQ(v.y, 2 * 3);
    EXPECT_EQ(v.z, 3 * 3);
}

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
}

}