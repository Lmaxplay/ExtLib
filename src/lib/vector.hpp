#include <iostream>
#include <math.h>
#include <any>

using std::any;


/**
 * @brief A vector2
 * 
 * @tparam T Type of the vector2
 */
template<typename T>
struct Vec2 : any {
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

    /** 
     * Calculates the magnitude of the vector2
     * 
     * @returns magnitude of the vector
     */
    T getmagnitude() {
        return std::sqrt(x * x + y * y);
    }


    template <typename T2>
    Vec2(const Vec2<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
    }; 

    Vec2(const T x, const T y) {
        this->x = x;
        this->y = y;
        return;
    }

    Vec2(const T x) {
        this->x = x;
        this->y = (T)0;
        return;
    }

    Vec2() {
        this->x = (T)0;
        this->y = (T)0;
        return;
    }
};

/**
 * @brief A vector3
 * 
 * @tparam T Type of the vector3
 */
template<typename T>
struct Vec3 : any {
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

    /** 
     * Calculates the magnitude of the vector3
     * 
     * @returns magnitude of the vector
     */
    T getmagnitude() {
        return std::sqrt(x * x + y * y + z * z);
    }

    template <typename T2>
    Vec3(const Vec3<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
    }; 
    
    Vec3(const T x, const T y, const T z) {
        this->x = x;
        this->y = y;
        this->z = z;
        return;
    }


    Vec3(const T x, const T y) {
        this->x = x;
        this->y = y;
        this->z = (T)0;
        return;
    }

    Vec3(const T x) {
        this->x = x;
        this->y = (T)0;
        this->z = (T)0;
        return;
    }

    Vec3() {
        this->x = (T)0;
        this->y = (T)0;
        this->z = (T)0;
        return;
    }
};

/**
 * @brief A vector4
 * 
 * @tparam T Type of the vector4
 */
template<typename T>
struct Vec4 : any {
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
    
    /** 
     * Calculates the magnitude of the vector4
     * 
     * @returns magnitude of the vector
     */
    T getmagnitude() {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }


    template <typename T2>
    Vec4(const Vec4<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
        this->w = (T)other.w;
    }; 
    
    Vec4(const T x, const T y, const T z, const T w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        return;
    }
    
    Vec4(const T x, const T y, const T z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = (T)0;
        return;
    }

    
    Vec4(const T x, const T y) {
        this->x = x;
        this->y = y;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    Vec4(const T x) {
        this->x = x;
        this->y = (T)0;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    Vec4() {
        this->x = (T)0;
        this->y = (T)0;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }
};

using vec2s = Vec2<short int>;
using vec2i = Vec2<int>;
using vec2l = Vec2<long>;
using vec2ll = Vec2<long long>;
using vec2f = Vec2<float>;
using vec2d = Vec2<double>;
using vec2ld = Vec2<long double>;

using vec3s = Vec3<short int>;
using vec3i = Vec3<int>;
using vec3l = Vec3<long>;
using vec3ll = Vec3<long long>;
using vec3f = Vec3<float>;
using vec3d = Vec3<double>;
using vec3ld = Vec3<long double>;

using vec4s = Vec4<short int>;
using vec4i = Vec4<int>;
using vec4l = Vec4<long>;
using vec4ll = Vec4<long long>;
using vec4f = Vec4<float>;
using vec4d = Vec4<double>;
using vec4ld = Vec4<long double>;
