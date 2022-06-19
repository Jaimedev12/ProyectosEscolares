#include "Perro.h"
#include "Gato.h"
#include "Vaca.h"

#include <vector>

int main(){

    vector<Mamifero*> animales(9);

    Perro perro1("Chato", 3, "Chiquita"), perro2("Raúl", 5, "Grandota"), perro3("Ernesto", 2, "Bien mezclada");
    Gato gato1("Pelusa", 3, "Naranje"), gato2("Alfabeto", 2, "Gris"), gato3("Inge", 5, "Negro");
    Vaca vaca1("Lola", 5, true), vaca2("Aurora", 7, true), vaca3("Josefino", 16, false);

    animales[0] = &perro1;  animales[1] = &perro2;  animales[2] = &perro3;
    animales[3] = &gato1;   animales[4] = &gato2;   animales[5] = &gato3;
    animales[6] = &vaca1;   animales[7] = &vaca2;   animales[8] = &vaca3;

    for (int i = 0; i < animales.size(); i++){
        animales[i]->muestraDatos();
        animales[i]->comunicarse();
        cout << endl;
    }


    return 0;
}