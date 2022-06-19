#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <iostream>

using namespace std;

class Mamifero{

    protected:
        string nombre;
        int edad;

    public:
        Mamifero();
        Mamifero(string, int);

        virtual void muestraDatos();
        virtual void comunicarse() = 0;
};

Mamifero::Mamifero(){
    nombre = "";
    edad = 0;
}

Mamifero::Mamifero(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}

void Mamifero::muestraDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

#endif