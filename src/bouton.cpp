#include "bouton.h"

bouton::bouton(Rectangle rec,std::string t, void (*func)())
{
    btn = rec;
    titre = t;
    onClick = func;
}

bouton::~bouton()
{

}

// Getters
Rectangle bouton::getRectangle() const
{
    return btn;
}

std::string bouton::getTitre() const
{
    return titre;
}

// Setters
void bouton::setRectangle(const Rectangle& rec)
{
    btn = rec;
}

void bouton::setTitre(const std::string& t)
{
    titre = t;
}

void bouton::drawButton(){

    DrawRectangleRec(btn,color);
    DrawText(titre.c_str(),GetCenterPoint(btn).x,GetCenterPoint(btn).y,10,BLACK);
    // GetCenterPoint(btn);
}