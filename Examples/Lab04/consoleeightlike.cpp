#include "consoleeightlike.h"
#include <iostream>

using namespace std;

//namespace esl
//{

ConsoleEightLike::ConsoleEightLike()noexcept:
EightLike()
{}

ConsoleEightLike::ConsoleEightLike(const ConsoleEightLike &other):
    EightLike(other)
{}

ConsoleEightLike::ConsoleEightLike(ConsoleEightLike &&other)noexcept:
EightLike(other)
{}

ConsoleEightLike &ConsoleEightLike::operator=(const ConsoleEightLike &other)
{
    return *this;
}

ConsoleEightLike &ConsoleEightLike::operator=(ConsoleEightLike && other)noexcept
{
    return *this;
}

ConsoleEightLike::~ConsoleEightLike() noexcept
{}


void ConsoleEightLike::output()const
{
    PositionedData *array = nullptr;
    int size = 0;
    getElements(array, size);
    printElements(array, size);
    delete [] array;
    array = nullptr;
}

void ConsoleEightLike::printElements(PositionedData *array, int size)const
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i].position == PositionedData::head)
            cout << "(" << array[i].datum << ")";
        else
            cout << array[i].datum;

        cout << " ";
    }

    cout << endl;
}

//}//namespace esl
