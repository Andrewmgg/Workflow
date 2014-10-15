#include "eightlike.h"

//namespace els{

class EightLike::Implementation
{
public:
	// Great 6
	Implementation()noexcept;
	Implementation(const Implementation &other);
	Implementation(Implementation &&other)noexcept;
	Implementation &operator=(const Implementation &other);
	Implementation &operator=(Implementation &&other)noexcept;
	~Implementation() noexcept;

	//accessors
	Data onHead()const;
	Data onNextLeft()const;
	Data onPreviousLeft()const;
	Data onNextRight()const;
	Data onPreviousRight()const;

	//modificators
	void pushLeft(Data datum);
	void pushRight(Data datum);
	void popLeft()noexcept;
	void popRight()noexcept;
	void moveForward()noexcept;
	void moveBackward()noexcept;
	void clear()noexcept;

	/// return EightLike as linear array, previously left, than head, then right;
	void getElements(PositionedData *&array, int &size)const;
private:
	struct Node
	{
		Data datum;
		Node *next, *previous;
	} *head;
};

EightLike::Implementation::Implementation()noexcept:
	head(nullptr)
{}

EightLike::Implementation::Implementation(const Implementation &other):
	head(nullptr)
{
	//TODO
}

EightLike::Implementation::Implementation(Implementation &&other)noexcept:
	head(nullptr)
{
	//TODO
}

EightLike::Implementation &EightLike::Implementation::operator=(const Implementation &other)
{
	//TODO
	return *this;
}

EightLike::Implementation &EightLike::Implementation::operator=(Implementation &&other)noexcept
{
	//TODO
	return *this;
}

EightLike::Implementation::~Implementation() noexcept
{
	//TODO
}


Data EightLike::Implementation::onHead()const
{
	//TODO
	return 0;
}

Data EightLike::Implementation::onNextLeft()const
{
	//TODO
	return 0;
}

Data EightLike::Implementation::onPreviousLeft()const
{
	//TODO
	return 0;
}

Data EightLike::Implementation::onNextRight()const
{
	//TODO
	return 0;
}

Data EightLike::Implementation::onPreviousRight()const
{
	//TODO
	return 0;
}



void EightLike::Implementation::pushLeft(Data datum)
{
	//TODO
}

void EightLike::Implementation::pushRight(Data datum)
{
	//TODO
}

void EightLike::Implementation::popLeft()noexcept
{
	//TODO
}

void EightLike::Implementation::popRight()noexcept
{
	//TODO
}

void EightLike::Implementation::moveForward()noexcept
{
	//TODO
}

void EightLike::Implementation::moveBackward()noexcept
{
	//TODO
}

void EightLike::Implementation::clear()noexcept
{
	//TODO
}


void EightLike::Implementation::getElements(PositionedData *&array, int &size)const
{
	//TODO
}

//}//namespace els
