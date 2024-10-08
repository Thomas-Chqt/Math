/*
 * ---------------------------------------------------
 * Matrix3x3f.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/28 11:46:24
 * ---------------------------------------------------
 */

#include "Math/Matrix.hpp"
#include "Math/Vector.hpp"
#include "UtilsCPP/RuntimeError.hpp"
#include <cmath>

namespace math
{

mat3x3::Matrix()
    : m_data{ vec3f(0, 0, 0),
              vec3f(0, 0, 0),
              vec3f(0, 0, 0) }
{
}

mat3x3::Matrix(float s)
    : m_data{ vec3f(s, 0, 0),
              vec3f(0, s, 0),
              vec3f(0, 0, s) }
{
}

mat3x3::Matrix(const vec3f& v1, const vec3f& v2, const vec3f& v3)
    : m_data{ v1, v2, v3 }
{
}

mat3x3::Matrix(float x0, float x1, float x2, float y0, float y1, float y2, float z0, float z1, float z2)
    : m_data{ vec3f(x0, y0, z0),
              vec3f(x1, y1, z1),
              vec3f(x2, y2, z2) }
{
}

mat3x3::Matrix(const mat4x4& mat)
    : m_data{ vec3f(mat[0].xyz()),
              vec3f(mat[1].xyz()),
              vec3f(mat[2].xyz()) }
{
}

vec3f& mat3x3::operator [] (utils::uint8 idx)
{
    if (idx >= 3)
        throw utils::RuntimeError("out of bound");
    return m_data[idx]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
}

const vec3f& mat3x3::operator [] (utils::uint8 idx) const
{
    if (idx >= 3)
        throw utils::RuntimeError("out of bound");
    return m_data[idx]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
}

template<>
MATH_API vec3f operator * (const vec3f& v, const mat3x3& m)
{
    return {
        m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
        m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
        m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z
    };
}

template<>
MATH_API vec3f operator * (const mat3x3& m, const vec3f& v)
{
    return {
        m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z,
        m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z,
        m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z
    };
}

template<>
MATH_API mat3x3 operator * (const mat3x3& lhs, const mat3x3& rhs)
{
    return {
        lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2],
        lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2],
        lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2],

        lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2],
        lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2],
        lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2],

        lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2],
        lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2],
        lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2]
    };
}

mat3x3 mat3x3::rotation(const vec3f& rads)
{
    using std::cos;
    using std::sin;

    math::mat3x3 rotX(
        1,           0,            0,
        0, cos(rads.x), -sin(rads.x),
        0, sin(rads.x),  cos(rads.x)
    );

    math::mat3x3 rotY(
        cos(rads.y), 0, sin(rads.y),
                  0, 1,           0,
       -sin(rads.y), 0, cos(rads.y)
    );

    math::mat3x3 rotZ(
        cos(rads.z), -sin(rads.z), 0,
        sin(rads.z),  cos(rads.z), 0,
                  0,            0, 1
    );

    return rotY * rotX * rotZ;
}

mat3x3 mat3x3::scale(const vec3f& vals)
{
    return {
        vals.x,      0,      0,
             0, vals.y,      0,
             0,      0, vals.z
    };
}

mat3x3 mat3x3::translation(const vec2f& vals)
{
    return {
        1, 0, vals.x,
        0, 1, vals.y,
        0, 0,      1
    };
}

}