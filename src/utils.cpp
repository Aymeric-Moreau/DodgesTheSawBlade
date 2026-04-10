#include "utils.h"


Vector2& operator+=(Vector2& a, const Vector2& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2& operator-=(Vector2& a, const Vector2& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2 operator+(Vector2 a, const Vector2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2 operator*(Vector2 a, const float b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

Vector2 GetCenterPoint(const Rectangle& r){
    return {r.x + r.width * 0.5f, r.y + r.height * 0.5f};
}