#include <iostream>
#include <math.h>

template<typename T>
struct Vec2 {
    T x;
    T y;

    Vec2<T> operator + (Vec2<T> other) { return {x + other.x, y + other.y }; };
    Vec2<T> operator - (Vec2<T> other) { return {x - other.x, y - other.y }; };
    Vec2<T> operator * (Vec2<T> other) { return {x * other.x, y * other.y }; };
    Vec2<T> operator / (Vec2<T> other) { return {x / other.x, y / other.y }; };

    T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;
            break;

            case 1:
            return y;
            break;

            default:
            throw std::out_of_range();
            return x;
            break;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
    {
        os << vec.x << ", " << vec.y;
        return os;
    }
    
    T getmagnitude() {
        return std::sqrt(x * x + y * y);
    }
};

template<typename T>
struct Vec3 {
    T x;
    T y;
    T z;

    Vec3<T> operator + (Vec3<T> other) { return {x + other.x, y + other.y, z + other.z }; };
    Vec3<T> operator - (Vec3<T> other) { return {x - other.x, y - other.y, z - other.z }; };
    Vec3<T> operator * (Vec3<T> other) { return {x * other.x, y * other.y, z * other.z }; };
    Vec3<T> operator / (Vec3<T> other) { return {x / other.x, y / other.y, z / other.z }; };

    T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;
            break;

            case 1:
            return y;
            break;

            case 2:
            return z;
            break;

            default:
            throw std::out_of_range("Out of range item");
            return x;
            break;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3<T>& vec)
    {
        os << vec.x << ", " << vec.y << ", " << vec.z;
        return os;
    }
    
    T getmagnitude() {
        return std::sqrt(x * x + y * y + z * z);
    }
};

template<typename T>
struct Vec4 {
    T x;
    T y;
    T z;
    T w;

    Vec4<T> operator + (Vec4<T> other) { return {x + other.x, y + other.y, z + other.z, w + other.w }; };
    Vec4<T> operator - (Vec4<T> other) { return {x - other.x, y - other.y, z - other.z, w - other.w }; };
    Vec4<T> operator * (Vec4<T> other) { return {x * other.x, y * other.y, z * other.z, w * other.w }; };
    Vec4<T> operator / (Vec4<T> other) { return {x / other.x, y / other.y, z / other.z, w / other.w }; };
    
    T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;
            break;

            case 1:
            return y;
            break;

            case 2:
            return z;
            break;
            
            case 3:
            return w;
            break;

            default:
            throw std::out_of_range("Out of range item");
            return x;
            break;
        }
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Vec4<T>& vec)
    {
        os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
        return os;
    }

    T getmagnitude() {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }
};

using vec2i = Vec2<int>;
using vec2l = Vec2<long>;
using vec2f = Vec2<float>;
using vec2d = Vec2<double>;

using vec3i = Vec3<int>;
using vec3l = Vec3<long>;
using vec3f = Vec3<float>;
using vec3d = Vec3<double>;

using vec4i = Vec4<int>;
using vec4l = Vec4<long>;
using vec4f = Vec4<float>;
using vec4d = Vec4<double>;