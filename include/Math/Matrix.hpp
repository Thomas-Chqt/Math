/*
 * ---------------------------------------------------
 * Matrix.hpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 11:50:59
 * ---------------------------------------------------
 */

#ifndef MATRIX_HPP
# define MATRIX_HPP

#include "UtilsCPP/Types.hpp"
#include "Vector.hpp"

namespace math
{

template<utils::uint8 C, utils::uint8 R, typename T> class Matrix;

using mat4x4 = Matrix<4, 4, float>;

template<>
class Matrix<4, 4, float>
{
public:
    Matrix();
    Matrix(const Matrix&) = default;
    Matrix(Matrix&&)      = default;

    Matrix(float s);

    Matrix(const vec4f& v1,
           const vec4f& v2,
           const vec4f& v3,
           const vec4f& v4);
    
    Matrix(float x0, float x1, float x2, float x3,
           float y0, float y1, float y2, float y3,
           float z0, float z1, float z2, float z3,
           float w0, float w1, float w2, float w3);
private:
    vec4f m_data[4];

public:
    vec4f& operator[](utils::uint8 idx);
    const vec4f& operator[](utils::uint8 idx) const;
};

vec4f operator * (const vec4f& v, const mat4x4& m);
vec4f operator * (const mat4x4& m, const vec4f& v);

mat4x4 operator * (const mat4x4& lhs, const mat4x4& rhs);

}

#endif // MATRIX_HPP