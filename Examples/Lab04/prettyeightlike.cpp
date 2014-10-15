#include "prettyeightlike.h"
#include <iostream>

using namespace std;

//namespace esl
//{

PrettyEightLike::PrettyEightLike()noexcept:
ConsoleEightLike()
{}

PrettyEightLike::PrettyEightLike(const PrettyEightLike &other):
    ConsoleEightLike(other)
{}

PrettyEightLike::PrettyEightLike(PrettyEightLike &&other)noexcept:
ConsoleEightLike(other)
{}

PrettyEightLike &PrettyEightLike::operator=(const PrettyEightLike &other)
{
    return *this;
}

PrettyEightLike &PrettyEightLike::operator=(PrettyEightLike && other)noexcept
{
    return *this;
}

PrettyEightLike::~PrettyEightLike() noexcept
{}

inline int filter(int value)noexcept
{
    return value < 0 ? 0 : value;
}

void PrettyEightLike::printElements(PositionedData *array, int size)const
{
    if(size)
    {
        int numberOfLeft = countLeft(array, size);
        int numberOfRight = size - numberOfLeft - 1;
        int leftPadding = filter(numberOfRight - numberOfLeft);
        int rightPadding = filter(numberOfLeft - numberOfRight);
        cout << endl;

        for(int i = 0; i < leftPadding; ++i)
            cout << " ";

        cout << "+";

        for(int i = 0; i < numberOfLeft - 1; ++i)
            cout << array[i].datum << "-";

        if(numberOfLeft > 0)
            cout << array[numberOfLeft - 1].datum;

        cout << "+" << endl;

        for(int i = 0; i < leftPadding; ++i)
            cout << " ";

        cout << "|";

        for(int i = 0; i < 2 * numberOfLeft - 1; ++i)
            cout << " ";

        cout << "|" << endl;

        for(int i = 0; i < leftPadding; ++i)
            cout << " ";

        cout << "+";

        for(int i = 0; i < 2 * numberOfLeft - 1; ++i)
            cout << "-";

        cout << "+" << endl;

        for(int i = 0; i < leftPadding + numberOfLeft; ++i)
            cout << " ";

        cout << "|" << endl;

        for(int i = 0; i < leftPadding + numberOfLeft; ++i)
            cout << " ";

        cout << array[numberOfLeft].datum << endl;

        for(int i = 0; i < leftPadding + numberOfLeft; ++i)
            cout << " ";

        cout << "|" << endl;

        for(int i = 0; i < rightPadding; ++i)
            cout << " ";

        cout << "+";

        for(int i = 0; i < 2 * numberOfRight - 1; ++i)
            cout << "-";

        cout << "+" << endl;

        for(int i = 0; i < rightPadding; ++i)
            cout << " ";

        cout << "|";

        for(int i = 0; i < 2 * numberOfRight - 1; ++i)
            cout << " ";

        cout << "|" << endl;

        for(int i = 0; i < rightPadding; ++i)
            cout << " ";

        cout << "+";

        for(int i = 0; i < numberOfRight - 1; ++i)
            cout << array[i + numberOfLeft + 1].datum << "-";

        if(numberOfRight > 0)
            cout << array[size - 1].datum;

        cout << "+" << endl << endl;
    }
    else
        cout << "+" << endl << endl;
}

int PrettyEightLike::countLeft(PositionedData *array, int size)noexcept
{
    int result = 0;

    while(result < size && array[result].position == PositionedData::left)
        ++result;

    return result;
}

//}//namespace esl

