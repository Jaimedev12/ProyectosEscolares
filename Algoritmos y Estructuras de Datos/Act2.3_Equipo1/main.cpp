/*
  *
  *  Para que funcione el código tiene que hacerlo con los casos
  *  de prueba
  *
  * Autores:
  *    Luis Barajas - A01235589
  *    María Fernanda Vela Calderón  -  A01377958
  *    Jaime Eduardo López Castro - A00833173  
  * Fecha: 05/07/2022
  *
  * Algoritmos de ordenamiento
  * 
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución - Casos de prueba:
  *  ./main < TestCases/test00.txt
  *  ./main < TestCases/test01.txt
  *  ./main < TestCases/test02.txt
  *  ./main < TestCases/test03.txt
  *  ./main < TestCases/test04.txt
  */

#include <iostream>
#include <fstream>
#include "Bitacora.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

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

int main() {

  cout << endl;
  
  Bitacora myBitacora;
  myBitacora.lecturaDatos("bitacora.txt");
  
  myBitacora.sortByDate();
  //myBitacora.print();  


  /*

  //cout << "Ejemplo de formato: Jun 13 01:25:12" << endl;
  //cout << "Fecha 1: " << endl;
  Registro date1 = askDate();
  
  //cout << "Fecha 2: " << endl;
  Registro date2 = askDate();

  // Los índices en los que están las fechas
  // -1 si no se encuentra
  DLLNode<Registro>* date1Ptr = myBitacora.findByDate(date1);
  DLLNode<Registro>* date2Ptr = myBitacora.findByDate(date2);

  
  if (date1Ptr == nullptr){
    cout << "No es encontró la primera fecha" << endl << endl;
    return 0;
  }

  if (date2Ptr == nullptr){
    cout << "No es encontró la segunda fecha" << endl << endl;
    return 0;
  }


  // Estas 2 líneas se encargan de crear los archivos txt,
  // están comentadas porque no hace falta que se creen varias veces
  //myBitacora.exportTxt("bitácora_ordenada.txt");
  //myBitacora.exportInRange(date1Ptr, date2Ptr, "resultado_búsqueda.txt");
  
  cout << endl;

  */
  

  
  return 0;
}
