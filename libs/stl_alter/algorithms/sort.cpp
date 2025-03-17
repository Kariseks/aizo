#ifndef SORT_CPP
#define SORT_CPP

#include <cstddef>



//template<typename T>
using T = unsigned long;
void insert_sort(T * tab, std::size_t size)
{
    if(size <= 1)
        return;

    for(int i=1; i<size; ++i)
    {
        T key_val = tab[i];

        for(int j=i; j >0; --j)
        {

        }
    }
}

#endif // SORT_CPP
