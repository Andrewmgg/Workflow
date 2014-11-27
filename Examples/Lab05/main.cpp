#include <iostream>
#include <exception>
#include <regex>
#include <cstdlib>
#include "filters.h"

using namespace std;
using namespace filter;

class Chain
{
public:
    // Great VI
    Chain():
        begin(nullptr),
        end(nullptr)
    {}

    Chain(const Chain &other) = delete;
    Chain &operator=(const Chain &other) = delete;
    Chain(Chain &&other) = default;
    Chain &operator=(Chain && other) = default;
    ~Chain()
    {
        clear();
    }

    // /Great VI

    bool isEmpty()const
    {
        return begin == nullptr || end == nullptr;
    }

    bool canWork()const
    {
        return !isEmpty() && begin->mayBroadcast();
    }

    // sample это английский термин для одного отсчёта дискретного сигнала
    void processSample()const
    {
        if(!isEmpty())
        {
            AbstractFilter *p = begin;
            while(p->next() && p->mayBroadcast())
            {
                p->next()->recive(p->transmit());
                p = p->next();
            }
        }
    }

    void addFilter(AbstractFilter *newFilter)
    {
        if(isEmpty())
            begin = newFilter;
        else
            end->connect(newFilter);
        end = newFilter;
    }

    void clear()
    {
        while(begin)
        {
            AbstractFilter *p = begin;
            begin = begin->next();
            delete p;
        }
        end = nullptr;
    }

private:
    AbstractFilter *begin, *end;
};

void printMenu();

int main()
{
    try
    {
        Chain chain;
        chain.addFilter(new FileEmiter("input.txt"));

        int choise;
        do
        {
            printMenu();
            char str[256];
            cin.getline(str, 256);
            choise = -1;
            if(regex_match(str, regex("^(0|[1-9]\\d*)$")))
                choise = atoi(str);
            switch(choise)
            {
            case 0://exit
                break;
            case 1:
                chain.addFilter(new Sumator(50));
                chain.addFilter(new Multiplyer(1.0 / 50.0));
                break;
            case 2:
                chain.addFilter(new Percintilizer(11));
                break;
            case 3:
                chain.addFilter(new Loop(50, 5));
                break;
            case 4:
                chain.addFilter(new Oscilator(20.0, 2.0, 0.01));
                break;
            default:
                cerr << "imposible input";
            }

        } while(choise);


        chain.addFilter(new FileReciver("output.txt"));

        while(chain.canWork())
            chain.processSample();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
    catch(...)
    {
        cerr << "something unexpected occurs\n";
    }

    return 0;
}

void printMenu()
{
    cout<<"Please, select next filter:\n\n";
    cout<<"1.\tAverage per 50 samples.\n";
    cout<<"2.\tMedian per 11 samples.\n";
    cout<<"3.\tLoop resonator base on 50 samples\n";
    cout<<"4.\tHarmonic oscilator with 50 samples in period\n";
    cout<<"0.\tFinish.\n";
}

