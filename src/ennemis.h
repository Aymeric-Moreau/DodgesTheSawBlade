#pragma once
#include "raylib.h"
#include <algorithm>

class ennemis
{
private:
    Vector2 position{10000 ,10000};
    Vector2 velocity{-25,25};
    float size = 20;
    Color color = RED;
public:
    ennemis();
    ~ennemis();
    void SpawnEnnemis();
    void DrawEnnemis();

    // --- Position ---
    Vector2 GetPosition();
    void SetPosition(Vector2 newPosition);

    // --- Velocity ---
    Vector2 GetVelocity();
    void SetVelocity(Vector2 newVelocity);
    void ApplyVelocity();
    Vector2 GetFuturePosition();

    // --- Size ---
    float GetSize();
    void SetSize(float newSize);

    // --- Color ---
    Color GetColor();
    void SetColor(Color newColor);
};