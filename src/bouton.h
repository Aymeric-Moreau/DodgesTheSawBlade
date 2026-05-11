#pragma once
#include "raylib.h"
#include "utils.h"
#ifndef BOUTON

class bouton
{
private:
    Rectangle btn;
    std::string titre;
    
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
// state(void (*initFunc)(),void (*logicFunc)(), void (*drawFunc)());


};

#endif