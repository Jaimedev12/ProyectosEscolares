#include "Complex.h"

int main(){

    Complex complex1(1, 3), complex2(2, 4);

    cout << "Número a sumar 1: " << endl;
    complex1.showData();

    cout << "Número a sumar 2: " << endl;
    complex2.showData();

    cout << "Resultado: " << endl;
    (complex1 + complex2).showData();


    cout << endl << endl;


    cout << "Número a restar 1: " << endl;
    complex1.showData();

    cout << "Número a restar 2: " << endl;
    complex2.showData();

    cout << "Resultado: " << endl;
    (complex1 - complex2).showData();

    return 0;
}