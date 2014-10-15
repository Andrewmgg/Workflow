#ifndef PRETTYEIGHTLIKE_H
#define PRETTYEIGHTLIKE_H

#include "consoleeightlike.h"

//namespace esl
//{

class PrettyEightLike: public ConsoleEightLike
{
    public:
        //Great 6
        PrettyEightLike()noexcept;
        PrettyEightLike(const PrettyEightLike &other);
        PrettyEightLike(PrettyEightLike &&other)noexcept;
        PrettyEightLike &operator=(const PrettyEightLike &other);
        PrettyEightLike &operator=(PrettyEightLike && other)noexcept;
        virtual ~PrettyEightLike() noexcept;
    private:
        void printElements(PositionedData *array, int size)const override;
        static int countLeft(PositionedData *array, int size)noexcept;
};


//}//namespace esl

#endif // PRETTYEIGHTLIKE_H
