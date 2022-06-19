#include "Mamifero.h"

class Vaca : public Mamifero{

    private:
        bool lechera;

    public:
        Vaca();
        Vaca(string, int, bool);

        void muestraDatos();
        void comunicarse();
};

Vaca::Vaca() : Mamifero(){
    lechera = NULL;
}

Vaca::Vaca(string name, int edad, bool lechera) : Mamifero(name, edad){
    this->lechera = lechera;
}

void Vaca::muestraDatos(){
    Mamifero::muestraDatos();
    cout << "¿Es lechera?: " << lechera << endl;
}

void Vaca::comunicarse(){
    cout << "Muuuuuuu" << endl;
}