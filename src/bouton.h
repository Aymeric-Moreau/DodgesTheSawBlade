#pragma once
#include "raylib.h"
#include "utils.h"
#ifndef BOUTON

class bouton
{
private:
    Rectangle btn;
    std::string titre;
    Color color = YELLOW;
    
    /* data */
public:
void (*onClick)();
    bouton(Rectangle rec,std::string t, void (*func)());
    ~bouton();

        // Getters
    Rectangle getRectangle() const;
    std::string getTitre() const;

    // Setters
    void setRectangle(const Rectangle& rec);
    void setTitre(const std::string& t);

    void drawButton();
// state(void (*initFunc)(),void (*logicFunc)(), void (*drawFunc)());


};

#endif