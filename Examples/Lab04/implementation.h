#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include "eightlike.h"

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

	//predicates
	bool isEmpty()const;

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
        ~Node();
	} *head;

	void copy(const Node *otherHead);
};

#endif // IMPLEMENTATION_H
