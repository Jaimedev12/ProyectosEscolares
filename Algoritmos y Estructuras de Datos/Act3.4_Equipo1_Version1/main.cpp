/*
  *
  * Autores:
  *    Luis Barajas - A01235589
  *    María Fernanda Vela Calderón  -  A01377958
  *    Jaime Eduardo López Castro - A00833173  
  * 
  * Fecha: 21/07/2022
  *
  * Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
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
  
  Bitacora myBitacora;
  
  myBitacora.lecturaDatos("bitacora_Heap.txt");
  
  myBitacora.sortRegistrosByIp();
  myBitacora.exportRegistrosToTxt("bitacora_ordenada.txt");
  
  myBitacora.contabilizarIP();
  myBitacora.sortDistinctIpsByRepeticiones();
  myBitacora.exportIpsToTxt("lista_de_ips.txt");

  // El número representa la cantidad de ips que vendrán en el txt
  myBitacora.exportIpsConMayorAcceso(5, "ips_con_mayor_acceso.txt");

  cout << endl;
  cout << "\tIP\t\t\tRepeticiones" << endl;
  myBitacora.printIpsConMayorAcceso(5);
  cout << endl;
  
}

