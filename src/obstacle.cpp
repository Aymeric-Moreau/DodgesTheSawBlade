#include "raylib.h"
#include "obstacle.h"
#include "utils.h"



obstacle::obstacle(Vector2 co, float width, float height)
{
    float thickness = 10.0f;

    // Rectangle principal
    mainRec = { co.x, co.y, width, height };

    // Gauche
    gaucheRec = {
        co.x - thickness + 5,
        co.y,
        thickness,
        height
    };

    // Droite
    droiteRec = {
        co.x + width - 5,
        co.y,
        thickness,
        height
    };

    // Haut
    hautRec = {
        co.x,
        co.y - thickness + 5,
        width,
        thickness
    };

    // Bas
    basRec = {
        co.x,
        co.y + height - 5,
        width,
        thickness
    };
}