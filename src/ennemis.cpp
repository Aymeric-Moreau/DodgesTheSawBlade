#include "utils.h"
#include "ennemis.h"
#include <iostream>


void ennemis::DrawEnnemis()
{

    DrawCircle(position.x, position.y, size, color);
    // std::cout << "dans draw ennemis position x: " << position.x << "position y: " << position.y << std::endl;
}

ennemis::ennemis()
{

}

ennemis::~ennemis() {}


// --- Position ---
Vector2 ennemis::GetPosition() { return position; }
void ennemis::SetPosition(Vector2 newPosition) { position = newPosition; }

// --- Velocity ---
Vector2 ennemis::GetVelocity() { return velocity; }
void ennemis::SetVelocity(Vector2 newVelocity) { velocity = newVelocity; }
void ennemis::ApplyVelocity(){
    position = Vector2Add(position, Vector2Scale(velocity, GetFrameTime()));

    // std::cout << "position x: " << position.x << "position y: " << position.y << std::endl;
}

Vector2 ennemis::GetFuturePosition()
{
    return Vector2Add(position, Vector2Scale(velocity, GetFrameTime()));
}

// --- Size ---
float ennemis::GetSize() { return size; }
void ennemis::SetSize(float newSize) { size = newSize; }

// --- Color ---
Color ennemis::GetColor() { return color; }
void ennemis::SetColor(Color newColor) { color = newColor; }

    direction ennemis::GetDir(){return dir;}
    void ennemis::SetDir(direction newDir){dir = newDir;
            switch (newDir)
        {
        case direction::BasDroite:
            SetVelocity(Vector2Multiply(MakePositive(GetVelocity()), BASDROITE));
            break;
           case direction::BasGauche:
            SetVelocity(Vector2Multiply(MakePositive(GetVelocity()), BASGAUCHE));
            break;
           case direction::HautDroite:
            SetVelocity(Vector2Multiply(MakePositive(GetVelocity()), HAUTDROITE));
            break;
           case direction::HautFauche:
            SetVelocity(Vector2Multiply(MakePositive(GetVelocity()), HAUTGAUCHE));
            break;
        
        default:
            break;
        }}

    void ennemis::Rebond(direction newDir)
    {
        SetDir(newDir);

    }