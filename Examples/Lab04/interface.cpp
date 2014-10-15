#include "implementation.h"
#include <utility>

using namespace std;

//namespace els{

EightLike::EightLike()noexcept:
	pimpl(nullptr)
{}

EightLike::EightLike(const EightLike &other):
	pimpl(nullptr)
{
	pimpl = new Implementation(*other.pimpl);
}

EightLike::EightLike(EightLike &&other)noexcept:
	pimpl(nullptr)
{
	swap(pimpl, other.pimpl);
}

EightLike &EightLike::operator=(const EightLike &other)
{
	*pimpl = *other.pimpl;
	return *this;
}

EightLike &EightLike::operator=(EightLike &&other)noexcept
{
	*pimpl = *other.pimpl;
	return *this;
}

EightLike::~EightLike() noexcept
{
	delete pimpl;
	pimpl = nullptr;
}


Data EightLike::onHead()const
{
	return pimpl->onHead();
}

Data EightLike::onNextLeft()const
{
	return pimpl->onNextLeft();
}

Data EightLike::onPreviousLeft()const
{
	return pimpl->onPreviousLeft();
}

Data EightLike::onNextRight()const
{
	return pimpl->onNextRight();
}

Data EightLike::onPreviousRight()const
{
	return pimpl->onPreviousRight();
}


bool EightLike::isEmpty()const
{
    return pimpl->isEmpty();
}

void EightLike::pushLeft(Data datum)
{
	pimpl->pushLeft(datum);
}

void EightLike::pushRight(Data datum)
{
	pimpl->pushRight(datum);
}

void EightLike::popLeft()noexcept
{
	pimpl->popLeft();
}

void EightLike::popRight()noexcept
{
	pimpl->popRight();
}

void EightLike::moveForward()noexcept
{
	pimpl->moveForward();
}

void EightLike::moveBackward()noexcept
{
	pimpl->moveBackward();
}

void EightLike::clear()noexcept
{
	pimpl->clear();
}


void EightLike::getElements(PositionedData *&array, int &size)const
{
	pimpl->getElements(array, size);
}

//}//namespace els
