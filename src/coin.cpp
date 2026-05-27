#include "coin.h"

coin::coin(Vector2 startPos)
{
    setPosition(startPos);
}

coin::~coin()
{
}

void coin::setPosition(Vector2 newPos){
    rec.x = newPos.x;
    rec.y = newPos.y;
}

void coin::drawCoin(){
    DrawRectanglePro({rec.x,rec.y -1,rec.width + 2 , rec.height +2}, {rec.width / 2, rec.height / 2}, 45.0f, BLACK);
    DrawRectanglePro(rec, {rec.width / 2, rec.height / 2}, 45.0f, color);
}

int coin::getRewardValue(){
    return reward;
}

Rectangle coin::getRec(){
    return rec;
}