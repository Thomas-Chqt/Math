/*
 * ---------------------------------------------------
 * Vector4f.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 11:22:30
 * ---------------------------------------------------
 */

#include "Math/Vector.hpp"
#include "UtilsCPP/Types.hpp"
#include <cmath>
#include <cstdlib>

using utils::uint8;

namespace math
{

vec4f::Vector() : x(0), y(0), z(0), w(0) // NOLINT(*-pro-type-member-init)
{
}

vec4f::Vector(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) // NOLINT(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-type-member-init)
{
}

vec4f::Vector(float arr[4]) : x(arr[0]), y(arr[1]), z(arr[2]), w(arr[3]) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
}

vec4f::Vector(vec3f xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
}

vec4f::Vector(vec2f xy, float z, float w) : x(xy.x), y(xy.y), z(z), w(w) // NOLINT(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-type-member-init)
{
}

vec4f::Vector(vec2f xy, vec2f zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) // NOLINT(cppcoreguidelines-pro-type-member-init)
{
}

float vec4f::length() const
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

void vec4f::normalize()
{
    float len = length();
    if (len == 0)
        return;

    x /= len;
    y /= len;
    z /= len;
    w /= len;
}

vec4f vec4f::normalized() const
{
    Vector v = *this;
    v.normalize();
    return v;
}

float& vec4f::operator[](uint8 idx)
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        case 2 : return z;
        case 3 : return w;
        default: std::abort(); // TODO use throw
    }
}

const float& vec4f::operator[](uint8 idx) const
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        case 2 : return z;
        case 3 : return w;
        default: std::abort(); // TODO use throw
    }
}

}