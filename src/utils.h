#pragma once
#include "raylib.h" 
#include "raymath.h"
#include <cmath>
// #include "C:/raylib/include/raymath.h"


    const Vector2 BASDROITE = {1 , 1};
    const Vector2 BASGAUCHE = {-1 , 1};
    const Vector2 HAUTDROITE = {1 , -1};
    const Vector2 HAUTGAUCHE = {-1 , -1};

    enum direction{BasDroite,BasGauche,HautDroite,HautFauche};

// Vector2& operator+=(Vector2& a, const Vector2& b);
// Vector2& operator-=(Vector2& a, const Vector2& b);
// Vector2 operator+(Vector2 a, const Vector2 b);
// Vector2 operator*(Vector2 a, const float b);
Vector2 MakePositive(Vector2 v);



