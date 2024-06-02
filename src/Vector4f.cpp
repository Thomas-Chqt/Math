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

vec4f::Vector() : x(0), y(0), z(0), w(0)
{
}

vec4f::Vector(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

vec4f::Vector(float arr[4]) : x(arr[0]), y(arr[1]), z(arr[2]), w(arr[3])
{
}

vec4f::Vector(vec2f v2fa, vec2f v2fb) : x(v2fa.x), y(v2fa.y), z(v2fb.x), w(v2fb.y)
{
}

vec4f::Vector(vec2f v2f, float z, float w) : x(v2f.x), y(v2f.y), z(z), w(w)
{
}

vec4f::Vector(vec3f v3f, float w) : x(v3f.x), y(v3f.y), z(v3f.z), w(w)
{
}

float vec4f::length() const
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

void vec4f::normalize()
{
    float len = length();

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