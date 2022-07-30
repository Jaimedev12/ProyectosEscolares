/*
  * Autores:
  *    Luis Barajas - A01235589
  *    María Fernanda Vela Calderón  -  A01377958
  *    Jaime Eduardo López Castro - A00833173  
  * Fecha: 19/07/2022
  * 
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución - Casos de prueba:
  *  ./main
  */

#include <iostream>
#include "MaxHeap.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

  cout << endl;
  cout << "Prueba de un MaxHeap" << endl;
  MaxHeap<int> maxHeap(100);

  // Insertando los números del 1 al 10
  for (int i = 1; i <= 10; i++){
    maxHeap.push(i);
  }
  cout << endl;

  cout << "Capacidad máxima: " << maxHeap.getCapacity() << endl << endl;

  maxHeap.print();
  cout << "Top: " << maxHeap.top() << endl;
  cout << endl;

  cout << "---------- Obteniendo los 5 números más grandes ----------" << endl << endl;
  for (int i = 0; i < 5; i++){    
    cout << "--- Eliminando raíz ---" << endl;
    maxHeap.pop();
    cout << "numElements: " << maxHeap.getNumElements() << endl;
    maxHeap.print();
    cout << "Top: " << maxHeap.top() << endl;
    cout << endl;
  }
 
  return 0;
}