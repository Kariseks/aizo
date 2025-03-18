#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "node.h"
#include <initializer_list>
#include <ostream>


//-------------------------------------------------------------------------------------------------
template<typename T>
class SingleList
{
public:
    SingleList() = default;
    SingleList(std::initializer_list<T> initList);
    ~SingleList();
public:
    void append(T value);
    void prepend(T value);
    bool insert(std::size_t idx, T value);

    bool remove(std::size_t idx);
    bool removeLast();
    bool removeFirst();

    bool set(std::size_t idx, T newValue);
    const T & at(std::size_t idx) const;
    T & at(std::size_t idx);
    T & operator[](std::size_t idx);
    const T & operator[](std::size_t idx) const;
    T* getNode(std::size_t idx);

    std::size_t getSize() const;
    bool isEmpty() const;
    void print(std::ostream &printDev) const;
private:
    T* getNode(std::size_t idx) const;
private:
    Node<T> * firstNode = nullptr;
    Node<T> * lastNode = nullptr;
    std::size_t size=0;
};

//*********************************************************************************************************************
template<typename T>
SingleList<T>::SingleList(std::initializer_list<T> initList)
{

}

template<typename T>
SingleList<T>::~SingleList()
{
    auto nodeToDelete = firstNode;
    Node<T> * nextNode;
    for(auto i = size; i >0; --i)
    {
        nextNode =  nodeToDelete->next;
        delete nodeToDelete;
        nodeToDelete = nextNode;

        #ifndef NDEBUG
            --size;
        #endif
    }
}
//=====================================================================================================================
template<typename T>
void SingleList<T>::append(T value)
{
    if(size == 0)   // empty list
    {
        firstNode = new Node{value};
        lastNode = firstNode;
    }
    else
    {
        lastNode->next = new Node{value};
        lastNode = lastNode->next;
    }
    ++size;
}

template<typename T>
void SingleList<T>::prepend(T value)
{
    if(size == 0)
    {
        firstNode = new Node{value};
        lastNode = firstNode;
    }
    else
    {
        firstNode = new Node{value, firstNode};
    }
    ++size;
}

template<typename T>
bool SingleList<T>::insert(std::size_t idx, T value)
{
    if(idx > size) //index out of range
        return false;
    else if(idx == size)
        append(value);

    else if(idx == 0)
        prepend(value);
    else
    {
        auto previous = getNode(idx-1);
        auto nextNode = previous->next;
        previous->next = new Node{value, nextNode};
        //previous->next = new Node{value, previous->next};
    }
    ++size;
    return true;
}
//=====================================================================================================================
template<typename T>
bool SingleList<T>::remove(std::size_t idx)
{
    if(idx >= size)
        return false;
    if(size < 2)
        return removeLast();

    auto previous = getNode(idx-1);
    auto nodeToRemove = previous->next;
    previous->next = nodeToRemove->next;
    delete nodeToRemove;
    --size;
    return true;
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
bool SingleList<T>::removeLast()
{
    if(size == 0)
        return false;

    if(size == 1)
    {
        delete firstNode;
        firstNode = nullptr;
        lastNode = nullptr;
    }
    else
    {
        auto previous = getNode(size-2);
        delete lastNode;
        previous->next = nullptr;
        lastNode = previous;
    }

    --size;
    return true;
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
bool SingleList<T>::removeFirst()
{
    if(size == 0)
        return false;
    if(size == 1)
    {
        delete firstNode;
        firstNode = nullptr;
        lastNode = nullptr;
    }
    else
    {
        auto next = firstNode->next;
        delete firstNode;
        firstNode = next;
    }
    --size;
    return true;
}
//=====================================================================================================================
template<typename T>
bool SingleList<T>::set(std::size_t idx, T value)
{
    if(idx >= size)
        return false;

    getNode(idx)->value = value;
    return true;
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
inline const T & SingleList<T>::at(std::size_t idx) const
{
    return const_cast<SingleList<T>*>(this)->at(idx);
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
T & SingleList<T>::at(std::size_t idx)
{
    auto node = getNode(idx);
    if(node == nullptr)
        throw std::out_of_range{"index is out of range"};

    return node->value;
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
inline const T & SingleList<T>::operator [](std::size_t idx) const
{
    return at(idx);
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
inline T & SingleList<T>::operator [](std::size_t idx)
{
    return at(idx);
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
T * SingleList<T>::getNode(std::size_t idx) const //private version
{
    if(idx >= size)
        return nullptr;
    auto node = firstNode;
    for(auto i = idx; i > 0; --i)
        node = node->next;
    return node;
}
template<typename T>
inline T * SingleList<T>::getNode(std::size_t idx)
{
    return const_cast<SingleList<T>*>(this)->getNode(idx);
}
//=====================================================================================================================
template<typename T>
std::size_t SingleList<T>::getSize() const
{
    return size;
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
bool SingleList<T>::isEmpty() const
{
    return size == 0;
}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
void SingleList<T>::print(std::ostream & printDev)    const
{
    auto iter = firstNode;
    for(std::size_t i = 0; i < size; ++i)
    {
        printDev << "[" << i << "]:= " << iter->value << std::endl;
        iter = iter->next;
    }
}
//---------------------------------------------------------------------------------------------------------------------
#endif // SINGLELIST_H
