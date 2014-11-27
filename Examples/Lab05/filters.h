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
    // Great VI
    Oscilator(double omega, double beta, double dt);
    Oscilator(const Oscilator &) = delete;
    Oscilator &operator =(const Oscilator &) = delete;
    Oscilator(Oscilator &&) = delete;
    Oscilator &operator=(Oscilator && ) = delete;
    ~Oscilator() {}
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;

private:
    double omega, beta, dt;
    double currentValue, previousValue;
    double currentVelocity, previousVelocity;
};

class Loop: public AbstractFilter
{
public:
    // Great VI
    Loop(int size, int multiplicity = 2);
    Loop(const Loop &other);
    Loop &operator=(const Loop &other) = delete;
    Loop(Loop &&other) = delete;
    Loop &operator=(Loop && other) = delete;
    ~Loop();
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;

private:
    double *bufer, *resonator;
    int size, multiplicity, buferSize, count, position;
    bool ready;
};

class Sumator: public AbstractFilter
{
public:
    // Great VI
    Sumator(int size);
    Sumator(const Sumator &other) = delete;
    Sumator &operator=(const Sumator &other) = delete;
    Sumator(Sumator &&other) = delete;
    Sumator &operator=(Sumator && other) = delete;
    ~Sumator();
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;
private:
    double *bufer;
    int size, position;
};

class Percintilizer: public AbstractFilter
{
public:
    // Great VI
    Percintilizer(int size, double ratio = 0.5);
    Percintilizer(const Percintilizer &other) = delete;
    Percintilizer &operator=(const Percintilizer &other) = delete;
    Percintilizer(Percintilizer &&other) = delete;
    Percintilizer &operator=(Percintilizer && other) = delete;
    ~Percintilizer();
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;
private:
    double *bufer;
    int size, count, position;
    const int place;
    bool ready;
};

class FileEmiter: public AbstractFilter
{
public:
    // Great VI
    FileEmiter(const char *filename);
    FileEmiter(const FileEmiter &other) = delete;
    FileEmiter &operator=(const FileEmiter &other) = delete;
    FileEmiter(FileEmiter &&other) = delete;
    FileEmiter &operator=(FileEmiter && other) = delete;
    ~FileEmiter();
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override;
private:
    class FileEmiterImplementation;
    FileEmiterImplementation *pimpl;
};

class FileReciver: public AbstractFilter
{
public:
    // Great VI
    FileReciver(const char *filename);
    FileReciver(const FileReciver &other) = delete;
    FileReciver &operator=(const FileReciver &other) = delete;
    FileReciver(FileReciver &&other) = delete;
    FileReciver &operator=(FileReciver && other) = delete;
    ~FileReciver();
    // /Great VI

    void recive(double input)override;
    double transmit()const override;
    bool mayBroadcast()const override
    {
        return false;
    }
private:
    class FileReciverImplementation;
    FileReciverImplementation *pimpl;
};


}


#endif // FILTERS_H
