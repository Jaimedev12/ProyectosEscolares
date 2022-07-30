/*
  * 
  * Autores:
  *    Luis Barajas - A01235589
  *    María Fernanda Vela Calderón  -  A01377958
  *    Jaime Eduardo López Castro - A00833173  
  * 
  * Fecha: 28/07/2022
  *
  * Act 5.2 -  Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)
  * 
  * Compilacion para debug:  
  *    g++ -std=c++17 -g -o main *.cpp 
  * Ejecucion con valgrind:
  *    nix-env -iA nixpkgs.valgrind
  *    valgrind --leak-check=full ./main 
  *
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución - Casos de prueba:
  *  ./main
*/

#include <iostream>
#include "Bitacora.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  
  cout << endl;

  try {
    Bitacora myBitacora;
  }
  catch (std::invalid_argument e) {
    std::cout << std::endl << "Ocurrio un error: " << e.what() << std::endl << "No se logro hacer la lectura del archivo para construir el grafo." << std::endl;
  }

}
