#include "implementation.h"
#include <cassert>
#include <exception>
#include <utility>

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

    Node *p = head->previous;

    while(p->previous != head)
        p = p->previous;

    return p->datum;
}

Data EightLike::Implementation::onPreviousLeft()const
{
    if(isEmpty())
        throw exception();

    return head->previous->datum;
}

Data EightLike::Implementation::onNextRight()const
{
    if(isEmpty())
        throw exception();

    return head->next->datum;
}

Data EightLike::Implementation::onPreviousRight()const
{
    if(isEmpty())
        throw exception();

    Node *p = head->next;

    while(p->next != head)
        p = p->next;

    return p->datum;
}

bool EightLike::Implementation::isEmpty()const
{
    return head == nullptr;
}

void EightLike::Implementation::pushLeft(Data datum)
{
    if(isEmpty())
    {
        Node *p = nullptr;
        p = new Node(datum);
        p->next = p;
        p->previous = p;
        swap(head, p);
    }
    else
    {
        Node *q = head->previous;

        while(q->previous != head)
            q = q->previous;

        Node *p = nullptr;
        p = new Node(datum);
        p->previous = head;
        p->next = q;
        q->previous = p;
    }
}

void EightLike::Implementation::pushRight(Data datum)
{
    if(isEmpty())
    {
        Node *p = nullptr;
        p = new Node(datum);
        p->next = p;
        p->previous = p;
        swap(head, p);
    }
    else
    {
        Node *q = head->next;

        while(q->next != head)
            q = q->next;

        Node *p = nullptr;
        p = new Node(datum);
        p->next = head;
        p->previous = q;
        q->next = p;
    }
}

void EightLike::Implementation::popLeft()noexcept
{
    if(!isEmpty())
    {
        if(head->previous == head)
        {
            if(head->next == head)
            {
                delete head;
                head = nullptr;
            }

        }
        else
        {
            Node *q = head->previous->previous;
            Node *p = head->previous;
            head->previous = q;

            if(q != head)
                q->next = head;

            delete p;
        }
    }
}

void EightLike::Implementation::popRight()noexcept
{
    if(!isEmpty())
    {
        if(head->next == head)
        {
            if(head->previous == head)
            {
                delete head;
                head = nullptr;
            }

        }
        else
        {
            Node *q = head->next->next;
            Node *p = head->next;
            head->next = q;

            if(q != head)
                q->previous = head;

            delete p;
        }
    }
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
    size = 0;
    array = nullptr;

    if(isEmpty())
        return;

    size = 1;
    Node *p = head->next;

    while(p != head)
    {
        ++size;
        p = p->next;
    }

    p = head->previous;

    while(p != head)
    {
        ++size;
        p = p->previous;
    }

    array = new PositionedData[size];
    int index = 0;
    p = head->previous;

    while(p != head)
    {
        array[index].datum = p->datum;
        array[index].position = PositionedData::left;
        ++index;
        p = p->previous;
    }

    array[index].datum = p->datum;
    array[index].position = PositionedData::head;
    ++index;
    p = p->next;

    while(p != head)
    {
        array[index].datum = p->datum;
        array[index].position = PositionedData::right;
        ++index;
        p = p->next;
    }
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

void EightLike::Implementation::copy(const Node *otherHead)
{
    if(otherHead)
    {
        Node *tempHead = nullptr, *p = nullptr;
        const Node *q = otherHead;
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

EightLike::Implementation::Node::Node(Data datum):
    datum(datum),
    next(nullptr),
    previous(nullptr)
{}

EightLike::Implementation::Node::~Node()
{
    next = nullptr;
    previous = nullptr;
}

//}//namespace els
