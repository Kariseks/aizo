#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node(){};
    Node(T value, Node<T> * next);
public:
    T value;
    Node<T> * next = nullptr;
};


//=================================================================================================
template <typename T>
Node<T>::Node(T value, Node<T> * next)
    : value(value),
    next{next}
{}
#endif // NODE_H
