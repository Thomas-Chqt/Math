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
    #include <ostream>
    #include "UtilsCPP/Types.hpp"
#endif // __METAL_VERSION__

#define METAL_FLOAT2_ALIGNEMENT 8
#define METAL_FLOAT3_ALIGNEMENT 16
#define METAL_FLOAT4_ALIGNEMENT 16

namespace math
{

#ifdef __METAL_VERSION__
    using vec2f = float2;
    using vec3f = float3;
    using vec4f = float4;
    
    using rgba  = vec4f;
    using rgb   = vec3f;

    // using vec2f = union{ struct{float x, y;      }; struct{float r, g;      }; };
    // using vec3f = union{ struct{float x, y, z;   }; struct{float r, g, b;   }; };
    // using vec4f = union{ struct{float x, y, z, w;}; struct{float r, g, b, a;}; };
#else

template<utils::uint8 L, typename T> struct Vector;

using vec2f = Vector<2, float>;
using vec3f = Vector<3, float>;
using vec4f = Vector<4, float>;
using rgba  = vec4f;
using rgb   = vec3f;

#define RED   math::rgba(1.0, 0.0, 0.0, 1.0)
#define GREEN math::rgba(0.0, 1.0, 0.0, 1.0)
#define BLUE  math::rgba(0.0, 0.0, 1.0, 1.0)
#define BLACK math::rgba(0.0, 0.0, 0.0, 1.0)
#define WHITE math::rgba(1.0, 1.0, 1.0, 1.0)

#define RED3   math::rgb(1.0, 0.0, 0.0)
#define GREEN3 math::rgb(0.0, 1.0, 0.0)
#define BLUE3  math::rgb(0.0, 0.0, 1.0)
#define BLACK3 math::rgb(0.0, 0.0, 0.0)
#define WHITE3 math::rgb(1.0, 1.0, 1.0)

template<>
struct alignas(METAL_FLOAT2_ALIGNEMENT) Vector<2, float>
{
    float x = 0; // NOLINT(misc-non-private-member-variables-in-classes)
    float y = 0; // NOLINT(misc-non-private-member-variables-in-classes)

    Vector()              = default;
    Vector(const Vector&) = default;
    Vector(Vector&&)      = default;

    Vector(float x, float y);
    explicit Vector(float arr[2]);

    float length() const;

    void normalize();
    Vector normalized() const;

    ~Vector() = default;

    Vector& operator = (const Vector&) = default;
    Vector& operator = (Vector&&)      = default;

    float& operator[](utils::uint8 idx);
    const float& operator[](utils::uint8 idx) const;
};

template<>
struct alignas(METAL_FLOAT3_ALIGNEMENT) Vector<3, float>
{
    union // NOLINT(misc-non-private-member-variables-in-classes)
    {
        struct{ float x, y, z; };
        struct{ float r, g, b; };
    };

    Vector();
    Vector(const Vector&) = default;
    Vector(Vector&&)      = default;

    Vector(float x, float y, float z);
    explicit Vector(float arr[3]);
    Vector(vec2f xy, float z);

    inline vec2f xy() const { return {x, y}; }

    float length() const;

    void normalize();
    Vector normalized() const;

    ~Vector() = default;

    Vector& operator = (const Vector&) = default;
    Vector& operator = (Vector&&)      = default;

    float& operator[](utils::uint8 idx);
    const float& operator[](utils::uint8 idx) const;
};

vec3f cross(const vec3f&, const vec3f&);

template<>
struct alignas(METAL_FLOAT4_ALIGNEMENT) Vector<4, float>
{
    union // NOLINT(misc-non-private-member-variables-in-classes)
    {
        struct{ float x, y, z, w; };
        struct{ float r, g, b, a; };
    };

    Vector();
    Vector(const Vector&) = default;
    Vector(Vector&&)      = default;

    Vector(float x, float y, float z, float w);
    explicit Vector(float arr[4]);
    Vector(vec3f xyz, float w);
    Vector(vec2f xy,  float z, float w);
    Vector(vec2f xy,  vec2f zw);

    inline vec2f xy() const { return {x, y}; }
    inline vec3f xyz() const { return {x, y, z}; }

    float length() const;

    void normalize();
    Vector normalized() const;

    ~Vector() = default;

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
Vector<L, float> operator + (const Vector<L, float>& lhs, const Vector<L, float>& rhs)
{
    float arr[L];

    for (utils::uint8 i = 0; i < L; i++)
        arr[i] = lhs[i] + rhs[i];

    return Vector<L, float>(arr);
}

template<utils::uint8 L>
inline Vector<L, float>& operator += (Vector<L, float>& lhs, const Vector<L, float>& rhs) { return lhs = lhs + rhs; }

template<utils::uint8 L>
Vector<L, float> operator - (const Vector<L, float>& lhs, Vector<L, float> rhs)
{
    return lhs + (-rhs);
}

template<utils::uint8 L>
inline Vector<L, float>& operator -= (Vector<L, float>& lhs, const Vector<L, float>& rhs) { return lhs = lhs - rhs; }

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

template<utils::uint8 L>
inline bool operator != (const Vector<L, float>& lhs, const Vector<L, float>& rhs) { return !(lhs == rhs); }

template<utils::uint8 L>
std::ostream& operator << (std::ostream& os, const Vector<L, float>& vec)
{
    os << '[';
    for (utils::uint8 i = 0; i < L; i++)
    {
        if(i > 0)
            os << ", ";
        os << vec[i];
    }
    os << ']';

    return os;
}

template<utils::uint8 L>
float dot(const Vector<L, float>& lhs, const Vector<L, float>& rhs)
{
    float output = 0;

    for (utils::uint8 i = 0; i < L; i++)
        output += lhs[i] * rhs[i];

    return output;
}


#endif // __METAL_VERSION__

}

#endif // VECTOR_HPP