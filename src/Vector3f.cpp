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

namespace math
{

vec3f::Vector() : x(0), y(0), z(0) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
}

vec3f::Vector(float x, float y, float z) : x(x), y(y), z(z) // NOLINT(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-type-member-init)
{
}

vec3f::Vector(float arr[3]) : x(arr[0]), y(arr[1]), z(arr[2]) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
}

vec3f::Vector(vec2f xy, float z) : x(xy.x), y(xy.y), z(z) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
}

float vec3f::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

void vec3f::normalize()
{
    float len = length();
    if (len == 0)
        return;
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

float& vec3f::operator[](utils::uint8 idx)
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        case 2 : return z;
        default: std::abort(); // TODO use throw
    }
}

const float& vec3f::operator[](utils::uint8 idx) const
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
    return {
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    };
}

}