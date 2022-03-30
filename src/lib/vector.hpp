#ifndef VECTORHPP
#define VECTORHPP
#include <iosfwd>
#include <math.h>

/**
 * @brief A vector2
 * 
 * @tparam T Type of the vector2
 */
template<typename T>
struct Vec2 {
    T x;
    T y;

    inline const Vec2<T> operator + (Vec2<T> other) { return {x + other.x, y + other.y }; };
    inline const Vec2<T> operator - (Vec2<T> other) { return {x - other.x, y - other.y }; };
    inline const Vec2<T> operator * (Vec2<T> other) { return {x * other.x, y * other.y }; };
    inline const Vec2<T> operator / (Vec2<T> other) { return {x / other.x, y / other.y }; };

    inline T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;

            case 1:
            return y;

            default:
            throw std::out_of_range("Out of range item");
            return x;
        }
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
    {
        os << vec.x << ", " << vec.y;
        return os;
    }

    template <typename T2>
    inline Vec2(const Vec2<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
    }; 

    inline Vec2(const T x, const T y) {
        this->x = x;
        this->y = y;
        return;
    }

    inline Vec2(const T x) {
        this->x = x;
        this->y = (T)0;
        return;
    }

    inline Vec2() {
        this->x = (T)0;
        this->y = (T)0;
        return;
    }
    
    // Returns the dot product of two vectors
    inline T dot(const Vec2<T> &other) {
        return x * other.x + y * other.y ;
    }

    // Returns the cross product of two vectors
    inline Vec2<T> cross(const Vec2<T> &other) {
        return {y * other.x - x * other.y, x * other.y - y * other.x};
    }
    
    // Returns the magnitude of the vector
    inline T magnitude() {
        return std::sqrt(x * x + y * y);
    }
    
    // Returns the normalized vector
    inline Vec2<T> normalize() {
        T mag = magnitude();
        return {x / mag, y / mag};
    }

    // Returns the length of the vector
    inline T length() {
        return std::sqrt(x * x + y * y);
    }

    // Returns the distance between two vectors
    inline T distance(const Vec2<T> &other) {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    // Returns the angle between two vectors
    inline T angle(const Vec2<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    // Returns the angle between two vectors in radians
    inline T angle_rad(const Vec2<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }
    
    // Returns the angle between two vectors in degrees
    inline T angle_deg(const Vec5<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude())) * 180 / M_PI;
    }

};

/**
 * @brief A vector3
 * 
 * @tparam T Type of the vector3
 */
template<typename T>
struct Vec3 {
    T x;
    T y;
    T z;

    inline const Vec3<T> operator + (Vec3<T> other) { return {x + other.x, y + other.y, z + other.z }; };
    inline const Vec3<T> operator - (Vec3<T> other) { return {x - other.x, y - other.y, z - other.z }; };
    inline const Vec3<T> operator * (Vec3<T> other) { return {x * other.x, y * other.y, z * other.z }; };
    inline const Vec3<T> operator / (Vec3<T> other) { return {x / other.x, y / other.y, z / other.z }; };

    inline T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;

            case 1:
            return y;

            case 2:
            return z;

            default:
            throw std::out_of_range("Out of range item");
            return x;
        }
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vec3<T>& vec)
    {
        os << vec.x << ", " << vec.y << ", " << vec.z;
        return os;
    }

    template <typename T2>
    inline Vec3(const Vec3<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
    }; 
    
    inline Vec3(const T x, const T y, const T z) {
        this->x = x;
        this->y = y;
        this->z = z;
        return;
    }


    inline Vec3(const T x, const T y) {
        this->x = x;
        this->y = y;
        this->z = (T)0;
        return;
    }

    inline Vec3(const T x) {
        this->x = x;
        this->y = (T)0;
        this->z = (T)0;
        return;
    }

    inline Vec3() {
        this->x = (T)0;
        this->y = (T)0;
        this->z = (T)0;
        return;
    }

    template <typename T2>
    inline Vec3(const Vec2<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)0;
    };
    
    // Returns the dot product of two vectors
    inline T dot(const Vec3<T> &other) {
        return x * other.x + y * other.y + z * other.z;
    }

    // Returns the cross product of two vectors
    inline Vec3<T> cross(const Vec3<T> &other) {
        return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
    }
    
    // Returns the magnitude of the vector
    inline T magnitude() {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    // Returns the normalized vector
    inline Vec3<T> normalize() {
        T mag = magnitude();
        return {x / mag, y / mag, z / mag};
    }

    // Returns the length of the vector
    inline T length() {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Returns the distance between two vectors
    inline T distance(const Vec3<T> &other) {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
    }

    // Returns the angle between two vectors
    inline T angle(const Vec3<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    // Returns the angle between two vectors in radians
    inline T angle_rad(const Vec3<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }
    
    // Returns the angle between two vectors in degrees
    inline T angle_deg(const Vec5<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude())) * 180 / M_PI;
    }
};

/**
 * @brief A vector4
 * 
 * @tparam T Type of the vector4
 */
template<typename T>
struct Vec4 {
    T x;
    T y;
    T z;
    T w;

    inline const Vec4<T> operator + (Vec4<T> other) { return {x + other.x, y + other.y, z + other.z, w + other.w }; };
    inline const Vec4<T> operator - (Vec4<T> other) { return {x - other.x, y - other.y, z - other.z, w - other.w }; };
    inline const Vec4<T> operator * (Vec4<T> other) { return {x * other.x, y * other.y, z * other.z, w * other.w }; };
    inline const Vec4<T> operator / (Vec4<T> other) { return {x / other.x, y / other.y, z / other.z, w / other.w }; };

    inline T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;

            case 1:
            return y;

            case 2:
            return z;
            
            case 3:
            return w;

            default:
            throw std::out_of_range("Out of range item");
            return x;
        }
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vec4<T>& vec)
    {
        os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
        return os;
    }


    template <typename T2>
    inline Vec4(const Vec4<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
        this->w = (T)other.w;
    }; 
    
    inline Vec4(const T x, const T y, const T z, const T w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        return;
    }
    
    inline Vec4(const T x, const T y, const T z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = (T)0;
        return;
    }

    
    inline Vec4(const T x, const T y) {
        this->x = x;
        this->y = y;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    inline Vec4(const T x) {
        this->x = x;
        this->y = (T)0;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    inline Vec4() {
        this->x = (T)0;
        this->y = (T)0;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    template <typename T2>
    inline Vec4(const Vec3<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
        this->w = (T)0;
    };

    template <typename T2>
    inline Vec4(const Vec2<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)0;
        this->w = (T)0;
    };

    // Returns the dot product of two vectors
    inline T dot(const Vec4<T> &other) {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    // Returns the cross product of two vectors
    inline Vec4<T> cross(const Vec4<T> &other) {
        return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, w * other.w};
    }
    
    // Returns the magnitude of the vector
    inline T magnitude() {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }
    
    // Returns the normalized vector
    inline Vec4<T> normalize() {
        T mag = magnitude();
        return {x / mag, y / mag, z / mag, w / mag};
    }

    // Returns the length of the vector
    inline T length() {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    // Returns the distance between two vectors
    inline T distance(const Vec4<T> &other) {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2) + std::pow(w - other.w, 2));
    }

    // Returns the angle between two vectors
    inline T angle(const Vec4<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    // Returns the angle between two vectors in radians
    inline T angle_rad(const Vec4<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }
    
    // Returns the angle between two vectors in degrees
    inline T angle_deg(const Vec5<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude())) * 180 / M_PI;
    }
};

/**
 * @brief A vector5
 * 
 * @tparam T Type of the vector5
 */
template<typename T>
struct Vec5 {
    T x;
    T y;
    T z;
    T w;
    T t;
    
    inline const Vec5<T> operator + (Vec5<T> other) { return {x + other.x, y + other.y, z + other.z, w + other.w, t + other.t }; };
    inline const Vec5<T> operator - (Vec5<T> other) { return {x - other.x, y - other.y, z - other.z, w - other.w, t - other.t }; };
    inline const Vec5<T> operator * (Vec5<T> other) { return {x * other.x, y * other.y, z * other.z, w * other.w, t * other.t }; };
    inline const Vec5<T> operator / (Vec5<T> other) { return {x / other.x, y / other.y, z / other.z, w / other.w, t / other.t }; };

    inline T& operator [] (int index) {
        switch(index) {
            case 0:
            return x;

            case 1:
            return y;

            case 2:
            return z;
            
            case 3:
            return w;

            case 4:
            return t;

            default:
            throw std::out_of_range("Out of range item");
            return x;
        }
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vec5<T>& vec)
    {
        os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ", " << vec.t;
        return os;
    }


    template <typename T2>
    inline Vec5(const Vec5<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
        this->w = (T)other.w;
        this->t = (T)other.t;
    }; 
    
    inline Vec5(const T x, const T y, const T z, const T w, const T t) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        this->t = t;
        return;
    }

    inline Vec5(const T x, const T y, const T z, const T w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        return;
    }
    
    inline Vec5(const T x, const T y, const T z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = (T)0;
        return;
    }

    
    inline Vec5(const T x, const T y) {
        this->x = x;
        this->y = y;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    inline Vec5(const T x) {
        this->x = x;
        this->y = (T)0;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    inline Vec5() {
        this->x = (T)0;
        this->y = (T)0;
        this->z = (T)0;
        this->w = (T)0;
        return;
    }

    template <typename T2>
    inline Vec5(const Vec4<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
        this->w = (T)other.w;
        this->t = (T)0;
    };

    template <typename T2>
    inline Vec5(const Vec3<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)other.z;
        this->w = (T)0;
        this->t = (T)0;
    };

    template <typename T2>
    inline Vec5(const Vec2<T2> &other) {
        this->x = (T)other.x;
        this->y = (T)other.y;
        this->z = (T)0;
        this->w = (T)0;
        this->t = (T)0;
    };

    // Returns the dot product of two vectors
    inline T dot(const Vec5<T> &other) {
        return x * other.x + y * other.y + z * other.z + w * other.w + t * other.t;
    }

    // Returns the cross product of two vectors
    inline Vec5<T> cross(const Vec5<T> &other) {
        return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, w * other.w, t * other.t};
    }
    
    // Returns the magnitude of the vector
    inline T magnitude() {
        return std::sqrt(x * x + y * y + z * z + w * w + t * t);
    }
    
    // Returns the normalized vector
    inline Vec5<T> normalize() {
        T mag = magnitude();
        return {x / mag, y / mag, z / mag, w / mag, t / mag};
    }

    // Returns the length of the vector
    inline T length() {
        return std::sqrt(x * x + y * y + z * z + w * w + t * t);
    }

    // Returns the distance between two vectors
    inline T distance(const Vec5<T> &other) {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2) + std::pow(w - other.w, 2) + std::pow(t - other.t, 2));
    }

    // Returns the angle between two vectors
    inline T angle(const Vec5<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    // Returns the angle between two vectors in radians
    inline T angle_rad(const Vec5<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    // Returns the angle between two vectors in degrees
    inline T angle_deg(const Vec5<T> &other) {
        return std::acos(dot(other) / (magnitude() * other.magnitude())) * 180 / M_PI;
    }
};

using vec2s  = Vec2<short int>;
using vec2i  = Vec2<int>;
using vec2l  = Vec2<long>;
using vec2ll = Vec2<long long>;
using vec2f  = Vec2<float>;
using vec2d  = Vec2<double>;
using vec2ld = Vec2<long double>;
using vec2c  = Vec2<char>;
using vec2uc = Vec2<unsigned char>;
using vec2ui = Vec2<unsigned int>;
using vec2ul = Vec2<unsigned long>;
using vec2ull = Vec2<unsigned long long>;

using vec3s  = Vec3<short int>;
using vec3i  = Vec3<int>;
using vec3l  = Vec3<long>;
using vec3ll = Vec3<long long>;
using vec3f  = Vec3<float>;
using vec3d  = Vec3<double>;
using vec3ld = Vec3<long double>;
using vec3c  = Vec3<char>;
using vec3uc = Vec3<unsigned char>;
using vec3ui = Vec3<unsigned int>;
using vec3ul = Vec3<unsigned long>;
using vec3ull = Vec3<unsigned long long>;

using vec4s  = Vec4<short int>;
using vec4i  = Vec4<int>;
using vec4l  = Vec4<long>;
using vec4ll = Vec4<long long>;
using vec4f  = Vec4<float>;
using vec4d  = Vec4<double>;
using vec4ld = Vec4<long double>;
using vec4c  = Vec4<char>;
using vec4uc = Vec4<unsigned char>;
using vec4ui = Vec4<unsigned int>;
using vec4ul = Vec4<unsigned long>;
using vec4ull = Vec4<unsigned long long>;

using vec5s  = Vec5<short int>;
using vec5i  = Vec5<int>;
using vec5l  = Vec5<long>;
using vec5ll = Vec5<long long>;
using vec5f  = Vec5<float>;
using vec5d  = Vec5<double>;
using vec5ld = Vec5<long double>;
using vec5c  = Vec5<char>;
using vec5uc = Vec5<unsigned char>;
using vec5ui = Vec5<unsigned int>;
using vec5ul = Vec5<unsigned long>;
using vec5ull = Vec5<unsigned long long>;

using int2  = Vec2<int>;
using long2  = Vec2<long>;
using float2  = Vec2<float>;
using double2  = Vec2<double>;
using long_double2  = Vec2<long double>;

using int3  = Vec3<int>;
using long3  = Vec3<long>;
using float3  = Vec3<float>;
using double3  = Vec3<double>;
using long_double3  = Vec3<long double>;

using int4  = Vec4<int>;
using long4  = Vec4<long>;
using float4  = Vec4<float>;
using double4  = Vec4<double>;
using long_double4 = Vec4<long double>;

using int5  = Vec5<int>;
using long5  = Vec5<long>;
using float5  = Vec5<float>;
using double5  = Vec5<double>;
using long_double5 = Vec5<long double>;

#endif