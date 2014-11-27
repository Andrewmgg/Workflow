#include <iostream>
#include "filters.h"

using namespace std;
using namespace filter;

int main()
{
    AbstractFilter *chain[2] = {new Multiplyer(0.5), new Oscilator(1,1,1)};
    cout << chain[0]->transmit() << endl << chain[1]->transmit() << endl;
    cout << "Hello World!" << endl;
    return 0;
}

