#pragma once
#include "raylib.h"
#include "utils.h"

#ifndef STATE

class state
{
private:
    /* data */
public:
    state(/* args */);
    ~state();
    virtual void initState();
    virtual void updateLogic();
    virtual void updateDraw();
};

#endif