#include "filters.h"

#include <vector>
#include <algorithm>

using namespace std;

namespace filter
{

Percintilizer::Percintilizer(int size, double ratio):
    bufer(nullptr),
    size(size),
    count(0),
    position(0),
    place(size*ratio),
    ready(false)
{

}

Percintilizer::~Percintilizer()
{

}

void Percintilizer::recive(double input)
{

}

double Percintilizer::transmit() const
{

}

bool Percintilizer::mayBroadcast() const
{
    return ready;
}

}
