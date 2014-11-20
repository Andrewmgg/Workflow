#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

namespace filter {

class AbstractFilter
{
public:
    // Great VI
    AbstractFilter(): mNext(nullptr) {}
    AbstractFilter(const AbstractFilter &) = delete;
    AbstractFilter &operator=(const AbstractFilter &) = delete;
    AbstractFilter(AbstractFilter &&) = delete;
    AbstractFilter &operator =(AbstractFilter && ) = delete;
    virtual ~AbstractFilter()
    {
        delete mNext;
        mNext = nullptr;
    }
    // /Great VI

    AbstractFilter *next() {
        return mNext;
    }

    void connect(AbstractFilter *next) {
        mNext = next;
    }

    virtual void recive(double input) = 0;
    virtual double transmit()const = 0;
    virtual bool mayBroadcast()const = 0;

private:
    AbstractFilter *mNext;
};

}

#endif // ABSTRACTFILTER_H
