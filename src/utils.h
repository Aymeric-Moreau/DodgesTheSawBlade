#pragma once
#include "raylib.h"

Vector2& operator+=(Vector2& a, const Vector2& b);
Vector2& operator-=(Vector2& a, const Vector2& b);
Vector2 operator+(Vector2 a, const Vector2 b);
Vector2 operator*(Vector2 a, const float b);

Vector2 GetCenterPoint(Rectangle r);
