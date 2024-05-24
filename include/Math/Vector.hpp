/*
 * ---------------------------------------------------
 * Vector.hpp
 *
 * Author: Thomas Choquet <thomas.publique@icloud.com>
 * Date: 2024/05/24 09:34:38
 * ---------------------------------------------------
 */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "UtilsCPP/Types.hpp"

namespace math
{

template<utils::uint8 L, typename T> struct Vector;

using vec2f = Vector<2, float>;
using vec3f = Vector<3, float>;
using vec4f = Vector<4, float>;
using rgba  = vec4f;

#define RED   rgba(1.0, 0.0, 0.0, 1.0)
#define GREEN rgba(0.0, 1.0, 0.0, 1.0)
#define BLUE  rgba(0.0, 0.0, 1.0, 1.0)
#define BLACK rgba(0.0, 0.0, 0.0, 1.0)
#define WHITE rgba(1.0, 1.0, 1.0, 1.0)

template<>
struct Vector<2, float>
{
    float x = 0;
    float y = 0;

    Vector()              = default;
    Vector(const Vector&) = default;
    Vector(Vector&&)      = default;

    Vector(float x, float y);
    Vector(float arr[2]);

    float length() const;

    void normalize();
    Vector normalized() const;

    Vector& operator = (const Vector&) = default;
    Vector& operator = (Vector&&)      = default;

    float& operator[](utils::uint8 idx);
    const float& operator[](utils::uint8 idx) const;
};

template<>
struct Vector<3, float>
{
    union
    {
        struct{ float x = 0, y = 0, z = 0; };
        struct{ float r    , g    , b    ; };
    };

    Vector()              = default;
    Vector(const Vector&) = default;
    Vector(Vector&&)      = default;

    Vector(float x, float y, float z);
    Vector(float arr[3]);
    Vector(vec2f v2f, float z);

    float length() const;

    void normalize();
    Vector normalized() const;

    Vector& operator = (const Vector&) = default;
    Vector& operator = (Vector&&)      = default;

    float& operator[](utils::uint8 idx);
    const float& operator[](utils::uint8 idx) const;
};

template<>
struct Vector<4, float>
{
    union
    {
        struct{ float x = 0, y = 0, z = 0, w = 0; };
        struct{ float r    , g    , b    , a    ; };
    };

    Vector()              = default;
    Vector(const Vector&) = default;
    Vector(Vector&&)      = default;

    Vector(float x, float y, float z, float w);
    Vector(float arr[4]);
    Vector(vec2f v2fa, vec2f v2fb);
    Vector(vec2f v2f, float z, float w);
    Vector(vec3f v3f, float w);

    float length() const;

    void normalize();
    Vector normalized() const;

    Vector& operator = (const Vector&) = default;
    Vector& operator = (Vector&&)      = default;

    float& operator[](utils::uint8 idx);
    const float& operator[](utils::uint8 idx) const;
};

template<utils::uint8 L>
Vector<L, float> operator - (const Vector<L, float>& v)
{
    float arr[L];

    for (utils::uint8 i = 0; i < L; i++)
        arr[i] = -v[i];

    return Vector<L, float>(arr);
}

template<utils::uint8 L>
Vector<L, float> operator + (const Vector<L, float>& lhs, Vector<L, float> rhs)
{
    float arr[L];

    for (utils::uint8 i = 0; i < L; i++)
        arr[i] = lhs[i] + rhs[i];

    return Vector<L, float>(arr);
}

template<utils::uint8 L>
Vector<L, float> operator - (const Vector<L, float>& lhs, Vector<L, float> rhs)
{
    return lhs + (-rhs);
}

template<utils::uint8 L>
Vector<L, float> operator * (const Vector<L, float>& lhs, float scalar)
{
    float arr[L];

    for (utils::uint8 i = 0; i < L; i++)
        arr[i] = lhs[i] * scalar;

    return Vector<L, float>(arr);
}

template<utils::uint8 L>
Vector<L, float>& operator *= (Vector<L, float>& lhs, float scalar)
{
    for (utils::uint8 i = 0; i < L; i++)
        lhs[i] *= scalar;
    return lhs;
}

template<utils::uint8 L>
Vector<L, float> operator / (const Vector<L, float>& lhs, float scalar)
{
    float arr[L];

    for (utils::uint8 i = 0; i < L; i++)
        arr[i] = lhs[i] / scalar;

    return Vector<L, float>(arr);
}

template<utils::uint8 L>
Vector<L, float>& operator /= (Vector<L, float>& lhs, float scalar)
{
    for (utils::uint8 i = 0; i < L; i++)
        lhs[i] /= scalar;
    return lhs;
}

}

#endif // VECTOR_HPP