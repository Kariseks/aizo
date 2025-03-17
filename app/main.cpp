#include "SingleList.h"
#include <iostream>

using namespace std;
#include <node.h>
#include <Array.h>

int main()
{

    SingleList<int> mojaLista;
    mojaLista.append(22);

    Node<int> node{};
    node.value = 25;
    cout << "Hello World!" << endl;


    Array<int, 10> array{0,1,2,3,4,5,6,7,8,9};

    array.print(std::cout);
    array.relocate(3,8);
    array.relocate(0,5);
    array.relocate(0,10);
    array.print(std::cout);

    return 0;
}
