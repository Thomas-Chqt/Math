/*
 * ---------------------------------------------------
 * Vector2f.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 11:02:02
 * ---------------------------------------------------
 */

#include "Math/Vector.hpp"
#include "UtilsCPP/Types.hpp"
#include <cmath>
#include <cstdlib>

using utils::uint8;

namespace math
{

vec2f::Vector(float x, float y) : x(x), y(y)
{
}

vec2f::Vector(float arr[2]) : x(arr[0]), y(arr[1])
{
}

float vec2f::length() const
{
    return std::sqrt(x * x + y * y);
}

void vec2f::normalize()
{
    float len = length();

    x /= len;
    y /= len;
}

vec2f vec2f::normalized() const
{
    Vector v = *this;
    v.normalize();
    return v;
}

float& vec2f::operator[](uint8 idx)
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        default: std::abort(); // TODO use throw
    }
}

const float& vec2f::operator[](uint8 idx) const
{
    switch (idx)
    {
        case 0 : return x;
        case 1 : return y;
        default: std::abort(); // TODO use throw
    }
}

}