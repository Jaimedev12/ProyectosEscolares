#include "Mamifero.h"

class Perro : public Mamifero{

    private:
        string raza;

    public:
        Perro();
        Perro(string, int, string);

        void muestraDatos();
        void comunicarse();
};

Perro::Perro() : Mamifero(){
    raza = "";
}

Perro::Perro(string name, int edad, string raza) : Mamifero(name, edad){
    this->raza = raza;
}

void Perro::muestraDatos(){
    Mamifero::muestraDatos();
    cout << "Raza: " << raza << endl;
}

void Perro::comunicarse(){
    cout << "Guau guau" << endl;
}

