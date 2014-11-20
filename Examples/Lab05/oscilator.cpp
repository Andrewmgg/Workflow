#include "filters.h"

namespace filter
{

void Oscilator::recive(double input)
{
    // TODO right
    currentValue = input;
}

double Oscilator::transmit() const
{
    return currentValue;
}

bool Oscilator::mayBroadcast() const
{
    return ready;
}

}
