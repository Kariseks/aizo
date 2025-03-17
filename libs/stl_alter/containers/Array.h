#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdexcept>

template<typename T,  std::size_t N>
//using T = int;
//constexpr int size = 50;
class Array
{
    static_assert(N > 0, "Array size must be greater than 0");
public:
    Array() = default;
    Array(std::initializer_list<T> list);

public:
    bool relocate(std::size_t srcIdx, std::size_t destIdx);
    T& operator[](std::size_t idx) noexcept(false);
    const T& operator[](std::size_t idx) const noexcept(false);

     T * data();
    const T * data() const;
    std::size_t getSize();

    void print(std::ostream & out = std::cout);

private:
    T tab[N];
    std::size_t size = N;
};
//*********************************************************************************************************************
//*********************************************************************************************************************
template<typename T, std::size_t N>
inline Array<T, N>::Array(std::initializer_list<T> list)
{
    std::size_t size = std::min(N,list.size());
    for(int i=0; i < size; ++i)
        tab[i] = *(list.begin()+i);
}
//=====================================================================================================================
template<typename T, std::size_t N>
bool Array<T, N>::relocate(std::size_t srcIdx, std::size_t destIdx)
{
    if(srcIdx >= size || destIdx >= size)   //out of range
        return false;

    if(srcIdx == destIdx)   //nothing to do
        return true;

    T elementToRelocate = tab[srcIdx];

    if(srcIdx < destIdx)    //we move the element forth
    {
        for(int i = srcIdx; i < destIdx;++i )  //point to where will be new value assign
            tab[i] = tab[i+1];

    }
    else    // we move the element back
    {
        for(int i = srcIdx; i > destIdx;)
            tab[i-1] = tab[i];  //can be faster ?

    }
    tab[destIdx] = elementToRelocate;
    return true;
}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t N>
T & Array<T, N>::operator[](std::size_t idx) noexcept(false)
{
    if(idx >= size )
        throw new std::out_of_range{"You provided a idx that is out of Array range"};

    return tab[idx];

}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t N>
const T & Array<T, N>::operator[](std::size_t idx) const noexcept(false)
{
    if(idx >= size )
        throw new std::out_of_range{"You provided a idx that is out of Array range"};

    return tab[idx];

}
//-------------------------------------------------------------------------------------------------
//=====================================================================================================================
template<typename T, std::size_t N>
inline const T *Array<T, N>::data() const
{
    return tab;
}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t N>
inline T *Array<T, N>::data()
{
    return tab;
}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t N>
inline std::size_t Array<T, N>::getSize()
{
    return size;
}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t  N>
inline void Array<T, N>::print(std::ostream & out)
{
    for(int i = 0; i < size; ++i)
        out << "[" << i << "]:=" << tab[i] << std::endl;
    out << std::endl;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------



#endif // ARRAY_H
