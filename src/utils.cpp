#include "utils.h"


// Vector2& operator+=(Vector2& a, const Vector2& b)
// {
//     a.x += b.x;
//     a.y += b.y;
//     return a;
// }

// Vector2& operator-=(Vector2& a, const Vector2& b)
// {
//     a.x -= b.x;
//     a.y -= b.y;
//     return a;
// }

// Vector2 operator+(Vector2 a, const Vector2 b)
// {
//     a.x += b.x;
//     a.y += b.y;
//     return a;
// }

// Vector2 operator*(Vector2 a, const float b)
// {
//     a.x *= b;
//     a.y *= b;
//     return a;
// }

Vector2 MakePositive(Vector2 v) {
    return { fabsf(v.x), fabsf(v.y) };
}