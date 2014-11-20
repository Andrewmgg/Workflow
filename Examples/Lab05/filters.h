#ifndef FILTERS_H
#define FILTERS_H

#include "abstractfilter.h"

namespace filter
{

class Multiplyer: public AbstractFilter
{
public:
    // Great VI
    Multiplyer(double multiplyer): mMultiplyer(multiplyer) {}
    Multiplyer(const Multiplyer &) = delete;
    Multiplyer &operator =(const Multiplyer &) = delete;
    Multiplyer(Multiplyer &&) = delete;
    Multiplyer &operator=(Multiplyer && ) = delete;
    ~Multiplyer() {}
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;
private:
    double mMultiplyer;
    double value;
};

class Oscilator: public AbstractFilter
{
public:
    // TODO Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;

private:
    double omega, beta;
    double currentValue, previousValue;
    bool ready;

};





}


#endif // FILTERS_H
