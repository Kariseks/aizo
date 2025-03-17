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


    Array<int, 24> array{};


    return 0;
}
