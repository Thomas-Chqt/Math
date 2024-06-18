/*
 * ---------------------------------------------------
 * VectorTestCases.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/06/15 11:32:42
 * ---------------------------------------------------
 */

#include <gtest/gtest.h>
#include "Math/Vector.hpp"

using namespace math;

namespace math_test
{

TEST(VectorTest, scaling)
{
    vec3f v = { 1, 2, 3 };

    v *= 3;

    EXPECT_EQ(v.x, 1 * 3);
    EXPECT_EQ(v.y, 2 * 3);
    EXPECT_EQ(v.z, 3 * 3);
}

TEST(VectorTest, sizeof)
{
    EXPECT_EQ(sizeof(vec2f), 8);
    EXPECT_EQ(sizeof(vec3f), 16);
    EXPECT_EQ(sizeof(vec4f), 16);
}

TEST(VectorTest, alignof)
{
    EXPECT_EQ(alignof(vec2f), 8);
    EXPECT_EQ(alignof(vec3f), 16);
    EXPECT_EQ(alignof(vec4f), 16);
}

TEST(VectorTest, crossProduct)
{
    EXPECT_EQ(cross(vec3f(1,3,4), vec3f(1,3,4)), vec3f(0,0,0));
    EXPECT_EQ(cross(vec3f(1,5,4), vec3f(1,3,4)), vec3f(8,0,-2));
    EXPECT_EQ(cross(vec3f(1,5,4), vec3f(1,9,4)), vec3f(-16,0,4));
}

TEST(VectorTest, dotProduct)
{
    EXPECT_EQ(dot(vec3f(1,2,3), vec3f(1,2,3)), 14);
    EXPECT_EQ(dot(vec3f(1,2,5), vec3f(1,2,3)), 20);
    EXPECT_EQ(dot(vec3f(1,2,5), vec3f(1,9,3)), 34);
}

}