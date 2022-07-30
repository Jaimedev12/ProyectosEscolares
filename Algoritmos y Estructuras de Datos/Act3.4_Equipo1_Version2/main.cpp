/*
  *
  * Autores:
  *    Luis Barajas - A01235589
  *    María Fernanda Vela Calderón  -  A01377958
  *    Jaime Eduardo López Castro - A00833173  
  * Fecha: 20/07/2022
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

/*
Registro askDate(){
  string mes;
  string dia;
  string hora;
  string min;
  string seg;

  std::getline(cin, mes, ' ');
  std::getline(cin, dia, ' ');
  std::getline(cin, hora, ':');
  std::getline(cin, min, ':');
  std::getline(cin, seg);
  Registro tmpReg(mes, dia, hora, min, seg, "", "", "");
  return tmpReg;
}
*/

int main() {
  
  cout << endl;
  
  Bitacora myBitacora;
  myBitacora.lecturaDatos("bitcra_Heap.txt");
  
  myBitacora.sortByIp();  
 
  myBitacora.contabilizarIP();
  myBitacora.topFive();
  
}
/*
Archivos:
  bitcra_Heap.txt  ->  Contiene los datos de bitacoraHeap.txt (descargado de canvas)
  bitacora_ordenada.txt  -> Contienen los datos de bitcra_Heap.txt(bitacoraHeap) ordenados por IP
  ips_con_mayor_acceso.txt -> Contiene las cinco IPs con más accesos.

Usados para comprobación:
  listaDeIps.txt -> Contiene los IPs con su recuento de repeticiones
  prioridadDeIps.txt -> Contiene los elementos del MaxHeap<Ip> 
*/
