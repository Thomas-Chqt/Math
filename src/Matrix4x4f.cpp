/*
 * ---------------------------------------------------
 * Matrix4x4f.cpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 11:58:45
 * ---------------------------------------------------
 */

#include "Math/Matrix.hpp"
#include "Math/Vector.hpp"
#include "UtilsCPP/RuntimeError.hpp"

namespace math
{

mat4x4::Matrix()
    : m_data{ Vector<4, float>(0, 0, 0, 0),
              Vector<4, float>(0, 0, 0, 0),
              Vector<4, float>(0, 0, 0, 0),
              Vector<4, float>(0, 0, 0, 0) }
{
}

mat4x4::Matrix(float s)
    : m_data{ Vector<4, float>(s, 0, 0, 0),
              Vector<4, float>(0, s, 0, 0),
              Vector<4, float>(0, 0, s, 0),
              Vector<4, float>(0, 0, 0, s) }
{
}

mat4x4::Matrix(const vec4f& v1, const vec4f& v2, const vec4f& v3, const vec4f& v4)
    : m_data{ v1, v2, v3, v4 }
{
}

mat4x4::Matrix(float x0, float x1, float x2, float x3, float y0, float y1, float y2, float y3, float z0, float z1, float z2, float z3, float w0, float w1, float w2, float w3)
    : m_data{ Vector<4, float>(x0, y0, z0, w0),
              Vector<4, float>(x1, y1, z1, w1),
              Vector<4, float>(x2, y2, z2, w2),
              Vector<4, float>(x3, y3, z3, w3) }
{
}

mat4x4::Matrix(const mat3x3& mat)
    : m_data { vec4f(mat[0],  0),
               vec4f(mat[1],  0),
               vec4f(mat[2],  0),
               vec4f(0, 0, 0, 1) }
{
}

float mat4x4::determinant() const
{
    return m_data[0][0] * m_data[1][1] * m_data[2][2] * m_data[3][3] - m_data[0][0] * m_data[1][1] * m_data[3][2] * m_data[2][3] + m_data[0][0] * m_data[2][1] * m_data[3][2] * m_data[1][3] - m_data[0][0] * m_data[2][1] * m_data[1][2] * m_data[3][3]
         + m_data[0][0] * m_data[3][1] * m_data[1][2] * m_data[2][3] - m_data[0][0] * m_data[3][1] * m_data[2][2] * m_data[1][3] - m_data[1][0] * m_data[2][1] * m_data[3][2] * m_data[0][3] + m_data[1][0] * m_data[2][1] * m_data[0][2] * m_data[3][3]
         - m_data[1][0] * m_data[3][1] * m_data[0][2] * m_data[2][3] + m_data[1][0] * m_data[3][1] * m_data[2][2] * m_data[0][3] - m_data[1][0] * m_data[0][1] * m_data[2][2] * m_data[3][3] + m_data[1][0] * m_data[0][1] * m_data[3][2] * m_data[2][3]
         + m_data[2][0] * m_data[3][1] * m_data[0][2] * m_data[1][3] - m_data[2][0] * m_data[3][1] * m_data[1][2] * m_data[0][3] + m_data[2][0] * m_data[0][1] * m_data[1][2] * m_data[3][3] - m_data[2][0] * m_data[0][1] * m_data[3][2] * m_data[1][3]
         + m_data[2][0] * m_data[1][1] * m_data[3][2] * m_data[0][3] - m_data[2][0] * m_data[1][1] * m_data[0][2] * m_data[3][3] - m_data[3][0] * m_data[0][1] * m_data[1][2] * m_data[2][3] + m_data[3][0] * m_data[0][1] * m_data[2][2] * m_data[1][3]
         - m_data[3][0] * m_data[1][1] * m_data[2][2] * m_data[0][3] + m_data[3][0] * m_data[1][1] * m_data[0][2] * m_data[2][3] - m_data[3][0] * m_data[2][1] * m_data[0][2] * m_data[1][3] + m_data[3][0] * m_data[2][1] * m_data[1][2] * m_data[0][3];
}

mat4x4 mat4x4::inversed() const
{
    const float det = determinant();
    if(det == 0.0F)
        throw utils::RuntimeError("matrix inversion error");

    const float invdet = 1.0F / det;

    mat4x4 res;
    res.m_data[0][0] = invdet  * (m_data[1][1] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3]) + m_data[2][1] * (m_data[3][2] * m_data[1][3] - m_data[1][2] * m_data[3][3]) + m_data[3][1] * (m_data[1][2] * m_data[2][3] - m_data[2][2] * m_data[1][3]));
    res.m_data[0][1] = -invdet * (m_data[0][1] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3]) + m_data[2][1] * (m_data[3][2] * m_data[0][3] - m_data[0][2] * m_data[3][3]) + m_data[3][1] * (m_data[0][2] * m_data[2][3] - m_data[2][2] * m_data[0][3]));
    res.m_data[0][2] = invdet  * (m_data[0][1] * (m_data[1][2] * m_data[3][3] - m_data[3][2] * m_data[1][3]) + m_data[1][1] * (m_data[3][2] * m_data[0][3] - m_data[0][2] * m_data[3][3]) + m_data[3][1] * (m_data[0][2] * m_data[1][3] - m_data[1][2] * m_data[0][3]));
    res.m_data[0][3] = -invdet * (m_data[0][1] * (m_data[1][2] * m_data[2][3] - m_data[2][2] * m_data[1][3]) + m_data[1][1] * (m_data[2][2] * m_data[0][3] - m_data[0][2] * m_data[2][3]) + m_data[2][1] * (m_data[0][2] * m_data[1][3] - m_data[1][2] * m_data[0][3]));
    
    res.m_data[1][0] = -invdet * (m_data[1][0] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3]) + m_data[2][0] * (m_data[3][2] * m_data[1][3] - m_data[1][2] * m_data[3][3]) + m_data[3][0] * (m_data[1][2] * m_data[2][3] - m_data[2][2] * m_data[1][3]));
    res.m_data[1][1] = invdet  * (m_data[0][0] * (m_data[2][2] * m_data[3][3] - m_data[3][2] * m_data[2][3]) + m_data[2][0] * (m_data[3][2] * m_data[0][3] - m_data[0][2] * m_data[3][3]) + m_data[3][0] * (m_data[0][2] * m_data[2][3] - m_data[2][2] * m_data[0][3]));
    res.m_data[1][2] = -invdet * (m_data[0][0] * (m_data[1][2] * m_data[3][3] - m_data[3][2] * m_data[1][3]) + m_data[1][0] * (m_data[3][2] * m_data[0][3] - m_data[0][2] * m_data[3][3]) + m_data[3][0] * (m_data[0][2] * m_data[1][3] - m_data[1][2] * m_data[0][3]));
    res.m_data[1][3] = invdet  * (m_data[0][0] * (m_data[1][2] * m_data[2][3] - m_data[2][2] * m_data[1][3]) + m_data[1][0] * (m_data[2][2] * m_data[0][3] - m_data[0][2] * m_data[2][3]) + m_data[2][0] * (m_data[0][2] * m_data[1][3] - m_data[1][2] * m_data[0][3]));
    
    res.m_data[2][0] = invdet  * (m_data[1][0] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3]) + m_data[2][0] * (m_data[3][1] * m_data[1][3] - m_data[1][1] * m_data[3][3]) + m_data[3][0] * (m_data[1][1] * m_data[2][3] - m_data[2][1] * m_data[1][3]));
    res.m_data[2][1] = -invdet * (m_data[0][0] * (m_data[2][1] * m_data[3][3] - m_data[3][1] * m_data[2][3]) + m_data[2][0] * (m_data[3][1] * m_data[0][3] - m_data[0][1] * m_data[3][3]) + m_data[3][0] * (m_data[0][1] * m_data[2][3] - m_data[2][1] * m_data[0][3]));
    res.m_data[2][2] = invdet  * (m_data[0][0] * (m_data[1][1] * m_data[3][3] - m_data[3][1] * m_data[1][3]) + m_data[1][0] * (m_data[3][1] * m_data[0][3] - m_data[0][1] * m_data[3][3]) + m_data[3][0] * (m_data[0][1] * m_data[1][3] - m_data[1][1] * m_data[0][3]));
    res.m_data[2][3] = -invdet * (m_data[0][0] * (m_data[1][1] * m_data[2][3] - m_data[2][1] * m_data[1][3]) + m_data[1][0] * (m_data[2][1] * m_data[0][3] - m_data[0][1] * m_data[2][3]) + m_data[2][0] * (m_data[0][1] * m_data[1][3] - m_data[1][1] * m_data[0][3]));
    
    res.m_data[3][0] = -invdet * (m_data[1][0] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2]) + m_data[2][0] * (m_data[3][1] * m_data[1][2] - m_data[1][1] * m_data[3][2]) + m_data[3][0] * (m_data[1][1] * m_data[2][2] - m_data[2][1] * m_data[1][2]));
    res.m_data[3][1] = invdet  * (m_data[0][0] * (m_data[2][1] * m_data[3][2] - m_data[3][1] * m_data[2][2]) + m_data[2][0] * (m_data[3][1] * m_data[0][2] - m_data[0][1] * m_data[3][2]) + m_data[3][0] * (m_data[0][1] * m_data[2][2] - m_data[2][1] * m_data[0][2]));
    res.m_data[3][2] = -invdet * (m_data[0][0] * (m_data[1][1] * m_data[3][2] - m_data[3][1] * m_data[1][2]) + m_data[1][0] * (m_data[3][1] * m_data[0][2] - m_data[0][1] * m_data[3][2]) + m_data[3][0] * (m_data[0][1] * m_data[1][2] - m_data[1][1] * m_data[0][2]));
    res.m_data[3][3] = invdet  * (m_data[0][0] * (m_data[1][1] * m_data[2][2] - m_data[2][1] * m_data[1][2]) + m_data[1][0] * (m_data[2][1] * m_data[0][2] - m_data[0][1] * m_data[2][2]) + m_data[2][0] * (m_data[0][1] * m_data[1][2] - m_data[1][1] * m_data[0][2]));

    return res;
}

vec4f& mat4x4::operator[](utils::uint8 idx)
{
    if (idx >= 4)
        throw utils::RuntimeError("out of bound");
    return m_data[idx]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
}

const vec4f& mat4x4::operator[](utils::uint8 idx) const
{
    if (idx >= 4)
        throw utils::RuntimeError("out of bound");
    return m_data[idx]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)
}

template<>
MATH_API vec4f operator * (const vec4f& v, const mat4x4& m)
{
    return {
        m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w,
        m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
        m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
        m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w
    };
}

template<>
MATH_API vec4f operator * (const mat4x4& m, const vec4f& v)
{
    return {
        m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w,
        m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w,
        m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2] * v.w,
        m[0][3] * v.x + m[1][3] * v.y + m[2][3] * v.z + m[3][3] * v.w
    };
}

template<>
MATH_API mat4x4 operator * (const mat4x4& lhs, const mat4x4& rhs)
{
    return {
        lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3],
        lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3],
        lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3],
        lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2] + lhs[3][0] * rhs[3][3],

        lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3],
        lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3],
        lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3],
        lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2] + lhs[3][1] * rhs[3][3],

        lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3],
        lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3],
        lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2] + lhs[3][2] * rhs[2][3],
        lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1] + lhs[2][2] * rhs[3][2] + lhs[3][2] * rhs[3][3],

        lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2] + lhs[3][3] * rhs[0][3],
        lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2] + lhs[3][3] * rhs[1][3],
        lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1] + lhs[2][3] * rhs[2][2] + lhs[3][3] * rhs[2][3],
        lhs[0][3] * rhs[3][0] + lhs[1][3] * rhs[3][1] + lhs[2][3] * rhs[3][2] + lhs[3][3] * rhs[3][3]
    };
}

mat4x4 mat4x4::translation(const vec3f& vals)
{
    return {
        1, 0, 0, vals.x,
        0, 1, 0, vals.y,
        0, 0, 1, vals.z,
        0, 0, 0,      1
    };
}

}