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

}