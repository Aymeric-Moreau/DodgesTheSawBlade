
#include "state.h"


state::state(/* args */)
{
}

// state::~state()
// {
// }

bool state::GetIsDisagreeOtherLogic() const
{
    return isDisagreeOtherLogic;
}

void state::SetIsDisagreeOtherLogic(bool value)
{
    isDisagreeOtherLogic = value;
}

bool state::GetIsDisagreeOtherDraw() const
{
    return isDisagreeOtherDraw;
}

void state::SetIsDisagreeOtherDraw(bool value)
{
    isDisagreeOtherDraw = value;
}

// GETTER
std::vector<bouton> state::GetActiveBouton() const
{
    return activeBouton;
}

// SETTER
void state::SetActiveBouton(std::vector<bouton> value)
{
    activeBouton = value;
}

// ADD
void state::AddActiveBouton(bouton value)
{
    activeBouton.push_back(value);
}