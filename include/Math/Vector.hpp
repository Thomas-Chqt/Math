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

#ifndef __METAL_VERSION__
    #include "UtilsCPP/Types.hpp"
#endif // __METAL_VERSION__

namespace math
{

#ifdef __METAL_VERSION__
    using vec2f = float2;
    using vec3f = float3;
    using vec4f = float4;
    
    using rgba  = vec4f;

    // using vec2f = union{ struct{float x, y;      }; struct{float r, g;      }; };
    // using vec3f = union{ struct{float x, y, z;   }; struct{float r, g, b;   }; };
    // using vec4f = union{ struct{float x, y, z, w;}; struct{float r, g, b, a;}; };
#else

template<utils::uint8 L, typename T> struct Vector;

using vec2f = Vector<2, float>;
using vec3f = Vector<3, float>;
using vec4f = Vector<4, float>;
using rgba  = vec4f;

#define RED   math::rgba(1.0, 0.0, 0.0, 1.0)
#define GREEN math::rgba(0.0, 1.0, 0.0, 1.0)
#define BLUE  math::rgba(0.0, 0.0, 1.0, 1.0)
#define BLACK math::rgba(0.0, 0.0, 0.0, 1.0)
#define WHITE math::rgba(1.0, 1.0, 1.0, 1.0)

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

    Vector();
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

    Vector();
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

template<utils::uint8 L>
bool operator == (const Vector<L, float>& lhs, const Vector<L, float>& rhs)
{
    bool output = true;

    for (utils::uint8 i = 0; i < L; i++)
        output &= lhs[i] == rhs[i];

    return output;
}

#endif // __METAL_VERSION__

}

#endif // VECTOR_HPP