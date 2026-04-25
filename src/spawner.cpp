#include "raylib.h"
#include "spawner.h"
#include "utils.h"


spawner::spawner()
{
}

spawner::~spawner()
{
}

    void spawner::setSpawnZone(Vector2 min, Vector2 max){MinSpawnZone = min; MaxSpawnZone = max;}
    Vector2 spawner::getMinSpawnZone(){return MinSpawnZone;}
    Vector2 spawner::getMaxSpawnZone(){return MaxSpawnZone;}

        void spawner::setDirectionPossible(std::vector<direction> newDirPossible){directionPossible = newDirPossible;}
    std::vector<direction> spawner::getDirectionPossible(){return directionPossible;}

        Vector2 spawner::getMinvelocity(){return minVelocity;}
    void spawner::setMinVelocity(Vector2 newMin){minVelocity = newMin;}
    Vector2 spawner::getMaxVelocity(){return maxVelocity;}
    void spawner::setMaxVelocity(Vector2 newMax){maxVelocity = newMax;}

    ennemis spawner::spawnEnnemy(){
        ennemi = ennemis();
        ennemi.SetPosition({(float)GetRandomValue((int)MinSpawnZone.x, (int)MaxSpawnZone.x) ,(float)GetRandomValue((int)MinSpawnZone.y, (int)MaxSpawnZone.y) });
        ennemi.SetVelocity({(float)GetRandomValue((int)minVelocity.x, (int)maxVelocity.x) ,(float)GetRandomValue((int)minVelocity.y, (int)maxVelocity.y) });
        ennemi.SetDir(directionPossible[GetRandomValue(0,directionPossible.size()-1)]);
        return ennemi;
    }
    