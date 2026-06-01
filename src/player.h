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
    int limiteMapGacuhe;
    int limiteMapDroite;
    float speed = 500.5;
    Vector2 jumpSpeed = {0, -800};
    bool alive = true;

    

public:
    float minVeloX = -50000;
    float maxVeloX = 50000;
    float maxVeloY = 50000;
    float minVeloY = -5000;
    player(Vector2 SpawnPoint);
    ~player();

    static const int TAILLECHARACTER = 20;

    Vector2 GetPosition();
    void SetPosition(Vector2 newPosition);
    void ApplyVelocity();
    Vector2 GetFuturePosition();

    bool GetAlive();

    Vector2 GetVelocity();
    void SetVelocity(Vector2 newVelocity);
    void SetVelocityX(float newVeloX);
    void SetVelocityY(float newVeloY);
    void ADDVelocity(Vector2 addedValue);
    void SubtractVelocity(Vector2 subtrackValue);

    State GetState();
    void SetState(State newState);
    void SetStateIsGrounded(bool newState);

    int GetLimiteMapGauche();
    int GetLimiteMapDroite();
    void SetLimiteMap(int limiteGauche, int limiteDroite);

    Color GetColor();
    void SetColor(Color newColor);
    void Death();

    void checkPlayerController();
};
#endif