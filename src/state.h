#pragma once
#include "raylib.h"
#include "utils.h"

#ifndef STATE

class state
{
protected:
    bool isDisagreeOtherLogic = false;
    bool isDisagreeOtherDraw = false;
private:

public:
    state(/* args */);
    ~state();
    virtual void initState(){}
    virtual void updateLogic(){}
    virtual void updateDraw(){}
       virtual bool GetIsDisagreeOtherLogic() const;
    virtual void SetIsDisagreeOtherLogic(bool value);

   virtual bool GetIsDisagreeOtherDraw() const;
   virtual void SetIsDisagreeOtherDraw(bool value);
};

#endif