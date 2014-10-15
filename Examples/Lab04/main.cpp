#include <iostream>
#include "consoleeightlike.h"

using namespace std;
//using namespace esl;

int main()
{
	ConsoleEightLike *p = nullptr;
	p = new ConsoleEightLike();

	p->pushLeft(1);
	p->output();
	p->pushLeft(2);
	p->output();
	p->pushLeft(3);
	p->output();
	p->pushRight(4);
	p->output();
	p->pushRight(5);
	p->output();
}
