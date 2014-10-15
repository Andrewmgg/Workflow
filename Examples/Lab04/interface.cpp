#include "eightlike.h"

//namespace els{

EightLike::EightLike()noexcept:
	pimpl(nullptr)
{}

EightLike::EightLike(const EightLike &other):
	pimpl(nullptr)
{
	//TODO
}

EightLike::EightLike(EightLike &&other)noexcept:
	pimpl(nullptr)
{
	//TODO
}

EightLike &EightLike::operator=(const EightLike &other)
{
	//TODO
	return *this;
}

EightLike &EightLike::operator=(EightLike &&other)noexcept
{
	//TODO
	return *this;
}

EightLike::~EightLike() noexcept
{
	//TODO
}


Data EightLike::onHead()const
{
	//TODO
	return 0;
}

Data EightLike::onNextLeft()const
{
	//TODO
	return 0;
}

Data EightLike::onPreviousLeft()const
{
	//TODO
	return 0;
}

Data EightLike::onNextRight()const
{
	//TODO
	return 0;
}

Data EightLike::onPreviousRight()const
{
	//TODO
	return 0;
}



void EightLike::pushLeft(Data datum)
{
	//TODO
}

void EightLike::pushRight(Data datum)
{
	//TODO
}

void EightLike::popLeft()noexcept
{
	//TODO
}

void EightLike::popRight()noexcept
{
	//TODO
}

void EightLike::moveForward()noexcept
{
	//TODO
}

void EightLike::moveBackward()noexcept
{
	//TODO
}

void EightLike::clear()noexcept
{
	//TODO
}


void EightLike::getElements(PositionedData *&array, int &size)const
{
	//TODO
}

//}//namespace els
