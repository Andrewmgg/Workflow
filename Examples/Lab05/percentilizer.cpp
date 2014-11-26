#include "filters.h"

#include <vector>
#include <algorithm>

using namespace std;

namespace filter
{

class RatioException:public exception
{
public:
    const char *what()const noexcept
    {
        return "filter::RatioException -- ratio for percintilizer isn't beetwen 0 and 1";
    }
};

Percintilizer::Percintilizer(int size, double ratio):
    bufer(nullptr),
    size(size),
    count(0),
    position(0),
    place(size *ratio),
    ready(false)
{
    if(place < 0 || place >= this->size)
        throw RatioException();
    bufer = new double[this->size];
}

Percintilizer::~Percintilizer()
{

}

void Percintilizer::recive(double input)
{
    bufer[position] = input;
    position = (position + 1) % size;
    if(count < size)
        ++count;
    ready = count >= size;
}

double Percintilizer::transmit() const
{
    vector<double> forSort;
    for(auto i=0;i<size;++i)
        forSort.push_back(bufer[i]);
    sort(forSort.begin(),forSort.end());
    return forSort[place];
}

bool Percintilizer::mayBroadcast() const
{
    return ready;
}

}
