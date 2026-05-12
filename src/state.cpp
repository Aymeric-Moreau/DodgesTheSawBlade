
#include "state.h"


state::state(/* args */)
{
}

state::~state()
{
}

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