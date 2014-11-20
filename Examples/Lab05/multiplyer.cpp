#include "filters.h"

namespace filter
{

void Multiplyer::recive(double input)
{
    value = mMultiplyer * input;
}

double Multiplyer::transmit() const
{
    return value;
}

bool Multiplyer::mayBroadcast() const
{
    return true;
}

}
