#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node() = default;
    Node(T value, Node<T> * next = nullptr);
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
