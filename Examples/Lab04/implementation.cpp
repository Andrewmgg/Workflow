#include "eightlike.h"

namespace els{

class Implementation
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

Implementation::Implementation()noexcept:
	head(nullptr)
{}

Implementation::Implementation(const Implementation &other):
	head(nullptr)
{
	//TODO
}

Implementation::Implementation(Implementation &&other)noexcept:
	head(nullptr)
{
	//TODO
}

Implementation::Implementation &operator=(const Implementation &other):
{
	//TODO
	return *this;
}

Implementation::Implementation &operator=(Implementation &&other)noexcept:
{
	//TODO
	return *this;
}

Implementation::~Implementation() noexcept
{
	//TODO
}


Data Implementation::onHead()const
{
	//TODO
	return 0;
}

Data Implementation::onNextLeft()const
{
	//TODO
	return 0;
}

Data Implementation::onPreviousLeft()const
{
	//TODO
	return 0;
}

Data Implementation::onNextRight()const
{
	//TODO
	return 0;
}

Data Implementation::onPreviousRight()const
{
	//TODO
	return 0;
}



void Implementation::pushLeft(Data datum)
{
	//TODO
}

void Implementation::pushRight(Data datum)
{
	//TODO
}

void Implementation::popLeft()noexcept
{
	//TODO
}

void Implementation::popRight()noexcept
{
	//TODO
}

void Implementation::moveForward()noexcept
{
	//TODO
}

void Implementation::moveBackward()noexcept
{
	//TODO
}

void Implementation::clear()noexcept
{
	//TODO
}


void Implementation::getElements(PositionedData *&array, int &size)const
{
	//TODO
}

}//namespace els
