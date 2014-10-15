#ifndef EIGHTLIKE_H
#define EIGHTLIKE_H

namespace els{ // eight like space

typedef int Data;

struct PositionedData // helper struct for getElements method
{
	Data datum;
	enum Position{head, left, right} position;
};

class EightLike
{
public:
	// Great 6
	EightLike()noexcept;
	EightLike(const EightLike &other);
	EightLike(EightLike &&other)noexcept;
	EightLike &operator=(const EightLike &other);
	EightLike &operator=(EightLike &&other)noexcept;
	~EightLike() noexcept;

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
protected:
	/// return EightLike as linear array, previously left, than head, then right;
	void getElements(PositionedData *&array, int &size)const;
private:
	class Implementation *pimpl;
};

#endif // EIGHTLIKE_H
