#include "utils.h"
#include "ennemis.h"
#include <iostream>


void ennemis::DrawEnnemis()
{

    DrawCircle(position.x, position.y, size, color);
    std::cout << "dans draw ennemis position x: " << position.x << "position y: " << position.y << std::endl;
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
    position += velocity * GetFrameTime();

    std::cout << "position x: " << position.x << "position y: " << position.y << std::endl;
}

Vector2 ennemis::GetFuturePosition()
{
    return position + velocity * GetFrameTime();
}

// --- Size ---
float ennemis::GetSize() { return size; }
void ennemis::SetSize(float newSize) { size = newSize; }

// --- Color ---
Color ennemis::GetColor() { return color; }
void ennemis::SetColor(Color newColor) { color = newColor; }