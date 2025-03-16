#include "SingleList.h"
#include <iostream>

using namespace std;
#include "../libs/stl_alter/containers/node.h"

int main()
{

    SingleList<int> mojaLista;
    mojaLista.append(22);

    Node<int> node{};
    node.value = 25;
    cout << "Hello World!" << endl;
    return 0;
}
