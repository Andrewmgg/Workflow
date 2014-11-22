#include "filters.h"

namespace filter
{

Sumator::Sumator(int size):
    bufer(nullptr),
    size(size),
    position(0)
{
    bufer = new double[this->size];

    for(auto i = 0; i < this->size; ++i)
        bufer[i] = 0.0;
}

Sumator::~Sumator()
{
    delete [] bufer;
    bufer = nullptr;
    size = 0;
}

void Sumator::recive(double input)
{
    bufer[position] = input;
    position = (position + 1) % size;
}

double Sumator::transmit() const
{
    double result = 0.0;
    for(auto i = 0; i < size; ++i)
        result += bufer[i];
    return result;
}

bool Sumator::mayBroadcast() const
{
    return true;
}

}
