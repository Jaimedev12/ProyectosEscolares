#include <iostream>
#include "ListTemplate.h"

using namespace std;

int main(){
    cout << "Template example:" << endl;
    ListTemplate<int> myList;

    myList.insert(15);
    myList.insert(10);
    myList.insert(5);
    myList.print();

    cout << endl;

    myList.erase();
    cout << "Tamaño: " << myList.getSize() << endl;
    myList.print();


    return 0;
}