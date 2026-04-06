#include "player.h"
#include "utils.h"

player::player(Vector2 SpawnPoint)
{
    position = SpawnPoint;
    velocity = {0, 0};
    state.isGrounded = false;
}

player::~player() {}

Vector2 player::GetPosition() { return position; }
void player::SetPosition(Vector2 newPosition) { position = newPosition; }

void player::ApplyVelocity() 
{
    position += velocity * GetFrameTime();
    position.x = std::clamp(position.x, (float)limiteMapGacuhe + TAILLECHARACTER / 2, (float)limiteMapDroite - TAILLECHARACTER / 2);
}

Vector2 player::GetFuturePosition()
{
    return position + velocity * GetFrameTime();
}

Vector2 player::GetVelocity() { return velocity; }
void player::SetVelocity(Vector2 newVelocity) { velocity = newVelocity; }
void player::ADDVelocity(Vector2 addedValue) { velocity += addedValue; }
void player::SubtractVelocity(Vector2 subtrackValue) { velocity -= subtrackValue; }

int player::GetLimiteMapGauche(){ return limiteMapGacuhe;}
    int player::GetLimiteMapDroite(){ return limiteMapDroite;}
    void player::SetLimiteMap(int limiteGauche, int limiteDroite){limiteMapDroite = limiteDroite; limiteMapGacuhe = limiteGauche;}


player::State player::GetState() { return state; }
void player::SetState(player::State newState) { state = newState; }
void player::SetStateIsGrounded(bool newState) { state.isGrounded = newState; }

Color player::GetColor() { return COLOR; }
void player::SetColor(Color newColor) { COLOR = newColor;};

void player::Death(){
    player::SetColor(BLACK);
}