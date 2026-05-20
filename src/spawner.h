#pragma once
#include "raylib.h"
#include "utils.h"
#include "ennemis.h"
#ifndef SPAWNER

class spawner
{
private: //{250 , -550} {-260 , -550}
    Vector2 MinSpawnZone{130 , -550};
    Vector2 MaxSpawnZone{-160 , -550};
std::vector<direction> directionPossible{BasDroite,BasGauche};
    Vector2 minVelocity{75,75};
    Vector2 maxVelocity{105,105};
    ennemis ennemi;

    /* data */
public:
float timer{0};
float delaySpawn{2};
    spawner(/* args */);
    ~spawner();
    void setSpawnZone(Vector2 min, Vector2 max);
    Vector2 getMinSpawnZone();
    Vector2 getMaxSpawnZone();
    void setDirectionPossible(std::vector<direction> newDirPossible);
    std::vector<direction> getDirectionPossible();
    Vector2 getMinvelocity();
    void setMinVelocity(Vector2 newMin);
    Vector2 getMaxVelocity();
    void setMaxVelocity(Vector2 newMax);
    ennemis spawnEnnemy();

};




#endif