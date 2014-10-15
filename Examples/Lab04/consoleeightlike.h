#ifndef CONSOLEEIGHTLIKE_H
#define CONSOLEEIGHTLIKE_H

#include "eightlike.h"

//namespace esl
//{

class ConsoleEightLike: public EightLike
{
public:
	//Great 6
	ConsoleEightLike()noexcept;
	ConsoleEightLike(const ConsoleEightLike &other);
	ConsoleEightLike(ConsoleEightLike &&other)noexcept;
	ConsoleEightLike &operator=(const ConsoleEightLike &other);
	ConsoleEightLike &operator=(ConsoleEightLike &&other)noexcept;
	virtual ~ConsoleEightLike() noexcept;

	//interface
	void output()const;
private:
   virtual void printElements(PositionedData * array, int size)const;
};

//}//namespace esl

#endif //CONSOLEEIGHTLIKE_H
