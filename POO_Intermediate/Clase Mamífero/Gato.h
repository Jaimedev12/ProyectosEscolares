#include "Mamifero.h"

class Gato : public Mamifero{

    private:
        string color;

    public:
        Gato();
        Gato(string, int, string);

        void muestraDatos();
        void comunicarse();
};

Gato::Gato() : Mamifero(){
    color = "";
}

Gato::Gato(string name, int edad, string color) : Mamifero(name, edad){
    this->color = color;
}

void Gato::muestraDatos(){
    Mamifero::muestraDatos();
    cout << "Color: " << color << endl;
}

void Gato::comunicarse(){
    cout << "Miau miau" << endl;
}