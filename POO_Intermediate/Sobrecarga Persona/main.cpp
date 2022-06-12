#include "Person.h"

int main(){

    Person pers1("Jaime", 10), pers2("Andrea", 8);

    cout << "Datos de persona 1: " << endl;
    pers1.showData();
    cout << endl;

    cout << "Datos de persona 2: " << endl;
    pers2.showData();
    cout << endl;

    cout << "Persona resultante: " << endl;
    (pers1 + pers2).showData();

    return 0;
}