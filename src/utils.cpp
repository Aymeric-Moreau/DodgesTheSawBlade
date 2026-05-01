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

std::string DirToString(direction dir)
{
    switch (dir)
    {
        case BasDroite: return "BasDroite";
        case BasGauche: return "BasGauche";
        case HautDroite: return "HautDroite";
        case HautFauche: return "HautGauche";
        default: return "Unknown";
    }
}

bool HasState(std::vector<gameState> vector ,gameState s)
{
    return std::find(vector.begin(), vector.end(), s) != vector.end();
}