#pragma once
#include "raylib.h"
#include "utils.h"
#include "bouton.h"

#ifndef STATE

class state
{
protected:
    bool isDisagreeOtherLogic = false;
    bool isDisagreeOtherDraw = false;
    std::vector<bouton> activeBouton;
private:

public:
    state(/* args */);
    virtual ~state() = default;
    virtual void initState(){}
    virtual void updateLogic(){}
    virtual void updateDraw(){}
       virtual bool GetIsDisagreeOtherLogic() const;
    virtual void SetIsDisagreeOtherLogic(bool value);

   virtual bool GetIsDisagreeOtherDraw() const;
   virtual void SetIsDisagreeOtherDraw(bool value);
      // GETTER
    virtual std::vector<bouton> GetActiveBouton() const;

    // SETTER
    virtual void SetActiveBouton(std::vector<bouton> value);

    // ADD
    virtual void AddActiveBouton(bouton value);
};

#endif