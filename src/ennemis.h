#pragma once
#include "raylib.h"
#include "obstacle.h"
#include <algorithm>

class ennemis
{
private:
    Vector2 position{10000 ,10000};
    Vector2 velocity{0,0};
    float size = 20;
    Color color = RED;
    direction dir = direction::BasDroite;
    
public:
    obstacle *dernierObstacleRebond;
    int nbrRebond{0};
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

    direction GetDir();
    void SetDir(direction newDir);
    void Rebond(direction newDir);

    
};