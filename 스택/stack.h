#ifndef __STACK_H
#define __STACK_H
#include <stddef.h>

template <typename T>
class Node
{
public :
    T value;
    Node <T>* link;
    Node () {};
    ~Node () {};
};

template <typename T>
class stack
{
private:
    Node <T>* head;
    Node <T>* tail;
    size_t Numelement;

public:
    stack () : head(nullptr), tail(nullptr), Numelement(0) {};
    ~stack () {};
    void push (T val); /* stack new node push */
    void pop (); /* stack pop top node (tail node) because of LIFO structure */
    void clear (); /* delete all elements in stack */
    bool empty (); /* if empty return true else return false */
    size_t size (); /* return stack size */
    T top (); /* return current stack's top (in this class, tail, it can be anything head or tail.. just define ourself) 
                    if it doesn't have top return -1 */
};

template <typename T>
void stack<T>::push (T val)
{
    Node<T>* nod = new Node<T>;
    nod->value = val;

    if (head == nullptr) /* 현재 stack이 비어있다면, */
    {
        head = nod;
        tail = nod;
    }
    else /* 현재 stack이 비어있지 않다면, */
    {
        nod->link = tail;
        tail = nod;
    }

    Numelement++;
}

template <typename T>
void stack<T>::pop ()
{

    if (head == tail) /* 원소가 한 개 이하일 경우, */
    {
        head = nullptr;
        tail = nullptr;
        delete head;
    }
    else /* 두 개 이상의 원소를 갖고 있다면, */
    {
        Node<T>* ptr = tail->link;
        tail = nullptr;
        delete tail;

        tail = ptr;
    }

    Numelement--;
}

template <typename T>
void stack<T>::clear ()
{
    while (tail != nullptr)
    {
        pop();
    }
}

template <typename T>
bool stack<T>::empty ()
{
    if (tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
size_t stack<T>::size ()
{
    return Numelement;
}

template <typename T>
T stack<T>::top ()
{
    return tail->value;
}

#endif