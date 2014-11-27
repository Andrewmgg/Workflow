#include "filters.h"

namespace filter
{

Oscilator::Oscilator(double omega, double beta, double dt):
    omega(omega),
    beta(beta),
    dt(dt),
    currentValue(0.0),
    previousValue(0.0),
    currentVelocity(0.0),
    previousVelocity(0.0)
{
}

void Oscilator::recive(double input)
{
    auto denominator = dt * dt * omega * omega - 1.0 - 2.0 * dt * beta;
    currentValue = -(dt * dt * input + dt * previousVelocity + 1.0 + 2.0 * dt * beta) / denominator;
    currentVelocity = (dt * omega * omega * previousValue - dt * input - previousVelocity) / denominator;
}

double Oscilator::transmit() const
{
    return currentValue;
}

bool Oscilator::mayBroadcast() const
{
    return true;
}

}
