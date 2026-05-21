#pragma once
#include "raylib.h"

#ifndef OBSTACLE_H
#define OBSTACLE_H

class obstacle
{
private:
    Rectangle mainRec;
    Rectangle droiteRec;
    Rectangle gaucheRec;
    Rectangle basRec;
    Rectangle hautRec;

public:
    obstacle(Vector2 co, float width, float height);
    ~obstacle() = default;

    // getters utiles pour debug / collisions
    Rectangle GetMain() const {  return mainRec; }
    Rectangle GetDroite() const { return droiteRec; }
    Rectangle GetGauche() const { return gaucheRec; }
    Rectangle GetBas() const { return basRec; }
    Rectangle GetHaut() const { return hautRec; }
};

#endif