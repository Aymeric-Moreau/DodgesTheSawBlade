#pragma once
#include "raylib.h"

#include <algorithm>

#ifndef PLAYERS

class player
{
public:
    struct State
    {
        bool isGrounded;
    };

private:
    Vector2 position;
    Vector2 velocity;
    State state;
    Color COLOR = { 128, 0, 128, 255 };

public:
    player(Vector2 SpawnPoint);
    ~player();

    static const int TAILLECHARACTER = 20;

    Vector2 GetPosition();
    void SetPosition(Vector2 newPosition);
    void ApplyVelocity(float minX, float maxX);
    Vector2 GetFuturePosition();

    Vector2 GetVelocity();
    void SetVelocity(Vector2 newVelocity);
    void ADDVelocity(Vector2 addedValue);
    void SubtractVelocity(Vector2 subtrackValue);

    State GetState();
    void SetState(State newState);
    void SetStateIsGrounded(bool newState);

    Color GetColor();
    void SetColor(Color newColor);
    void Death();
};
#endif