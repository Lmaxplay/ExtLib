template<typename T>
struct Vec2 {
    T x;
    T y;
    Vec2 operator + (Vec2 other) { return {x + other.x, y + other.y } }
    Vec2 operator - (Vec2 other) { return {x - other.x, y - other.y } }
    Vec2 operator * (Vec2 other) { return {x * other.x, y * other.y } }
    Vec2 operator / (Vec2 other) { return {x * other.x, y * other.y } }
};