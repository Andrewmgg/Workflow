#include "filters.h"
#include <cmath>

namespace filter
{

Loop::Loop(int size, int multiplicity):
    bufer(nullptr),
    resonator(nullptr),
    size(size),
    multiplicity(multiplicity),
    buferSize(size *multiplicity),
    count(0),
    position(0),
    ready(false)
{
    bufer = new double[buferSize];
    resonator = new double[this->size];
}

Loop::~Loop()
{
    delete [] resonator;
    resonator = nullptr;
    delete [] bufer;
    bufer = nullptr;
    count = 0;
    ready = false;
}

void Loop::recive(double input)
{
    bufer[position] = input;
    position = (position + 1) % buferSize;

    if(count < buferSize)
        ++count;
    else
        ready = true;
}

double Loop::transmit() const
{
    for(auto i = 0; i < size; ++i)
    {
        resonator[i] = 0.0;
        for(auto j = 0; j < size; ++j)
            resonator[i] += bufer[i + j * size];
    }

    double result = 0.0;
    for(auto i = 0; i < size; ++i)
        result += resonator[i] * resonator[i];

    return std::sqrt(result);
}

bool Loop::mayBroadcast() const
{
    return ready;
}

}
