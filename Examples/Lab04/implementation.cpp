#include "implementation.h"
#include <cassert>
#include <exception>

using namespace std;

//namespace els{

EightLike::Implementation::Implementation()noexcept:
    head(nullptr)
{}

EightLike::Implementation::Implementation(const Implementation &other):
    head(nullptr)
{
    copy(other.head);
}

EightLike::Implementation::Implementation(Implementation &&other)noexcept:
    head(nullptr)
{
    swap(head, other.head);
}

EightLike::Implementation &EightLike::Implementation::operator=(const Implementation &other)
{
    if(this != &other)
    {
        clear();
        copy(other.head);
    }
    return *this;
}

EightLike::Implementation &EightLike::Implementation::operator=(Implementation && other)noexcept
{
    swap(head, other.head);
    return *this;
}

EightLike::Implementation::~Implementation() noexcept
{
    clear();
}


Data EightLike::Implementation::onHead()const
{
    if(isEmpty())
        throw exception();
    return head->datum;
}

Data EightLike::Implementation::onNextLeft()const
{
    if(isEmpty())
        throw exception();
    return 0;
}

Data EightLike::Implementation::onPreviousLeft()const
{
    if(isEmpty())
        throw exception();
    return 0;
}

Data EightLike::Implementation::onNextRight()const
{
    if(isEmpty())
        throw exception();
    return 0;
}

Data EightLike::Implementation::onPreviousRight()const
{
    if(isEmpty())
        throw exception();
    return 0;
}

bool EightLike::Implementation::isEmpty()const
{
    return head == nullptr;
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


void EightLike::Implementation::getElements(PositionedData *&array, int &size)const
{
    //TODO
}

void EightLike::Implementation::clear()noexcept
{
    if(head)
    {
        if(head->next != head)
        {
            Node *p = head->next;

            while(p != head)
            {
                Node *q = p;
                p = p->next;
                delete q;
            }
        }

        if(head->previous != head)
        {
            Node *p = head->previous;

            while(p != head)
            {
                Node *q = p;
                p = p->previous;
                delete q;
            }
        }

        delete head;
        head = nullptr;
    }
}

void copy(const Node *otherHead)
{
    if(otherHead)
    {
        Node *tempHead = nullptr, *p = nullptr, *q = otherHead;
        p = new Node(otherHead->datum);
        tempHead = p;
        q = q->next;
        while(q != otherHead)
        {
            assert(q);
            assert(p);
            Node *r = nullptr;
            r = new Node(q->datum);
            p->next = r;
            r->previous = p;
            q = q->next;
            p = p->next;
        }
        p->next = tempHead;

        p = tempHead;
        q = otherHead;
        q = q->previous;
        while(q != otherHead)
        {
            assert(q);
            assert(p);
            Node *r = nullptr;
            r = new Node(q->datum);
            p->previous = r;
            r->next = p;
            q = q->previous;
            p = p->previous;
        }
        p->previous = tempHead;

        swap(head, tempHead);
    }
}

EightLike::Implementation::Node(Data datum):
    datum(datum),
    next(nullptr),
    previous(nullptr)
{}

EightLike::Implementation::~Node()
{
    next = nullptr;
    previous = nullptr;
}

//}//namespace els
