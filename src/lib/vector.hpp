template<typename T>
struct Vec2 {
    T x;
    T y;
    //Vec2(T x, T y);
    Vec2 operator + (Vec2 other);
    Vec2 operator - (Vec2 other);
    Vec2 operator / (Vec2 other);
    Vec2 operator * (Vec2 other);
};

using vec2i = Vec2<int>;
using vec2l = Vec2<long>;
using vec2f = Vec2<float>;
using vec2d = Vec2<double>;