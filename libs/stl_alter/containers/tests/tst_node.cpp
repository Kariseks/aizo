#include <catch2/catch_test_macros.hpp>


#include "Array.h"
template<typename T, std::size_t N>
bool arrayEquals(Array<T,N> arr1, Array<T,N> arr2)
{
    if(arr1.getSize() != arr2.getSize())
        return false;

    for(std::size_t i=0; i< arr1.getSize(); ++i)
    {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}



TEST_CASE("Unit tests for Array.h")
{
    Array<int, 10> array{0,1,2,3,4,5,6,7,8,9};

    INFO("Checking Array size");
    REQUIRE(array.getSize() == 10);

    INFO("Chcecking operator[]");
    REQUIRE_THROWS(array[11]);
    REQUIRE(array[0] == 0);
    REQUIRE(array[3] == 3);

    SECTION("INVALID index relocatoin")
    {
        INFO("Checking relocate");
        REQUIRE_FALSE(array.relocate(4,10));
        REQUIRE_FALSE(array.relocate(4,22));
        REQUIRE_FALSE(array.relocate(22,5));
    }
    SECTION("Relocating forward")
    {
        array.relocate(7,7);
        REQUIRE(arrayEquals(array, Array<int,10>{0,1,2,3,4,5,6,7,8,9}));

        INFO("Checking middle of array 3->8");
        array.relocate(3,8);
        REQUIRE(arrayEquals(array, Array<int,10>{0,1,2,4,5,6,7,8,3,9}));

        INFO("Checking  of array 0->5");
        array.relocate(0,5);
        REQUIRE(arrayEquals(array, Array<int,10>{1,2,4,5,6,0,7,8,3,9}));

        array.relocate(0,9);
        REQUIRE(arrayEquals(array, Array<int,10>{2,4,5,6,0,7,8,3,9,1}));
    }
}
