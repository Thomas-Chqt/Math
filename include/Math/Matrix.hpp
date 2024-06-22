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
using mat3x3 = Matrix<3, 3, float>;

template<>
class alignas(16) Matrix<4, 4, float>
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

    static mat4x4 rotation(const vec3f& rads);
    static mat4x4 translation(const vec3f& vals);
    static mat4x4 scale(const vec3f& vals);

private:
    vec4f m_data[4];

public:
    Matrix& operator = (const Matrix&) = default;
    Matrix& operator = (Matrix&&)      = default;

    vec4f& operator[](utils::uint8 idx);
    const vec4f& operator[](utils::uint8 idx) const;
};

template<>
class alignas(16) Matrix<3, 3, float>
{
public:
    Matrix();
    Matrix(const Matrix&) = default;
    Matrix(Matrix&&)      = default;

    Matrix(float s);

    Matrix(const vec3f& v1,
           const vec3f& v2,
           const vec3f& v3);
    
    Matrix(float x0, float x1, float x2,
           float y0, float y1, float y2,
           float z0, float z1, float z2);
private:
    vec3f m_data[3];

public:
    Matrix& operator = (const Matrix&) = default;
    Matrix& operator = (Matrix&&)      = default;

    vec3f& operator [] (utils::uint8 idx);
    const vec3f& operator [] (utils::uint8 idx) const;
};

template<utils::uint8 S>
Vector<S, float> operator * (const Vector<S, float>&, const Matrix<S, S, float>&);

template<utils::uint8 S>
inline Vector<S, float> operator *= (Vector<S, float>& vec, const Matrix<S, S, float>& mat) { return vec = vec * mat; }

template<utils::uint8 S>
Vector<S, float> operator * (const Matrix<S, S, float>&, const Vector<S, float>&);

template<utils::uint8 S>
Matrix<S, S, float> operator * (const Matrix<S, S, float>&, const Matrix<S, S, float>&);

template<utils::uint8 S>
inline Matrix<S, S, float> operator *= (Matrix<S, S, float>& lhs, const Matrix<S, S, float>& rhs) { return lhs = lhs * rhs; }

template<utils::uint8 S>
bool operator == (const Matrix<S, S, float>& lhs, const Matrix<S, S, float>& rhs)
{
    bool output = true;

    for (utils::uint8 i = 0; i < S; i++)
        output &= lhs[i] == rhs[i];

    return output;
}

}

#endif // MATRIX_HPP