#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <initializer_list>
#include <ostream>


//-------------------------------------------------------------------------------------------------
template<typename T>
class SingleList
{
public:
    SingleList();
    SingleList(std::initializer_list<T> initList);
public:
    void append(T value);
    void prepend(T value);
    bool insert(std::size_t idx, T value);

    bool remove(std::size_t idx);
    bool removeLast();
    bool removeFirst();

    bool set(std::size_t idx, T newValue);
    T get(std::size_t idx);
    T operator[](std::size_t idx);
    T* getNode(std::size_t idx);

    std::size_t getSize();
    bool isEmpty();
    void print(std::ostream printDev);
};

//*********************************************************************************************************************
template<typename T>
SingleList<T>::SingleList()
{

}

template<typename T>
SingleList<T>::SingleList(std::initializer_list<T> initList)
{

}
//=====================================================================================================================
template<typename T>
void SingleList<T>::append(T value)
{

}

template<typename T>
void SingleList<T>::prepend(T value)
{

}

template<typename T>
bool SingleList<T>::insert(std::size_t idx, T value)
{

}
//=====================================================================================================================
template<typename T>
bool SingleList<T>::remove(std::size_t idx)
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
bool SingleList<T>::removeLast()
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
bool SingleList<T>::removeFirst()
{

}
//=====================================================================================================================
template<typename T>
bool SingleList<T>::set(std::size_t idx, T newValue)
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
T SingleList<T>::get(std::size_t idx)
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
T SingleList<T>::operator[](std::size_t idx)
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
T *SingleList<T>::getNode(std::size_t idx)
{

}
//=====================================================================================================================
template<typename T>
std::size_t SingleList<T>::getSize()
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
bool SingleList<T>::isEmpty()
{

}
//---------------------------------------------------------------------------------------------------------------------
template<typename T>
void SingleList<T>::print(std::ostream printDev)
{

}
//---------------------------------------------------------------------------------------------------------------------
#endif // SINGLELIST_H
