#pragma once
#include "raylib.h"
#include "player.h"
#include "utils.h"
#include "ennemis.h"
#include "spawner.h"
#include "obstacle.h"
#include "bouton.h"
#include "state.h"
#include "gameManager.h"

#ifndef INMAINGAMESTATE

class inMainGameState : state
{
private:
const Vector2 SPAWNPOINT = {10, 12};
    player playerCharacter = player(SPAWNPOINT); // zone de spawn ennemis {250 , -550} {-260 , -550}

float speed = 500.5;
Vector2 jumpSpeed = {0, -800};
Vector2 gravity = {0, 25};

bool r;
Camera2D camera;

obstacle ground2 = obstacle({-2500, 200}, 5000, 100);
obstacle wallRight2 = obstacle({350, -2500}, 100, 5000);
obstacle wallLefts2 = obstacle({-360, -2500}, 100, 5000);

Rectangle ground = {-2500, 200, 5000, 10};
Rectangle wallRight = {350, -2500, 100, 5000};
Rectangle wallLefts = {-360, -2500, 100, 5000};
Rectangle area = {-350, -800, 800, 1000};
Rectangle btn = {0, 0, 100, 100};

std::array<Rectangle *, 3> limiteMap{&ground, &wallRight, &wallLefts};
std::array<obstacle *, 3> limiteMap2{&ground2, &wallRight2, &wallLefts2};

Vector2 centerPointRec;

std::vector<ennemis> listeEnnemis;
std::vector<ennemis> closeEnnemis;
ennemis test;
spawner spawnerPrincipal;

int limiteMapGauche{area.x};
int limiteMapDroite{area.x + area.width};

float deltaTime;

Vector2 mousePos;
public:
    inMainGameState(/* args */);
    ~inMainGameState();

    void initState();
    void updateLogic();
    void updateDraw();

    void startMainGame();
void applyGravity();
void drawUI();
void ennemisUpdate();
void playerInput();
void debugEnnemis(int i);
void spawnerManager();
void playerUpdate();
void drawMainGame();

};




#endif