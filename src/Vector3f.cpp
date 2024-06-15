/*
 * ---------------------------------------------------
 * Vector3f.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 11:10:49
 * ---------------------------------------------------
 */

#include "Math/Vector.hpp"
#include "UtilsCPP/Types.hpp"
#include <cmath>
#include <cstdlib>

using utils::uint8;

namespace math
{

vec3f::Vector() : x(0), y(0), z(0)
{
}

vec3f::Vector(float x, float y, float z) : x(x), y(y), z(z)
{
}

vec3f::Vector(float arr[3]) : x(arr[0]), y(arr[1]), z(arr[2])
{
}

vec3f::Vector(vec2f v2f, float z) : x(v2f.x), y(v2f.y), z(z)
{
}

float vec3f::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

void vec3f::normalize()
{
    float len = length();

    x /= len;
    y /= len;
    z /= len;
}

vec3f vec3f::normalized() const
{
    Vector v = *this;
    v.normalize();
    return v;
}

float& vec3f::operator[](uint8 idx)
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        case 2 : return z;
        default: std::abort(); // TODO use throw
    }
}

const float& vec3f::operator[](uint8 idx) const
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        case 2 : return z;
        default: std::abort(); // TODO use throw
    }
}

vec3f cross(const vec3f& lhs, const vec3f& rhs)
{
    return vec3f(
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    );
}

float dot(const vec3f& lhs, const vec3f& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

}