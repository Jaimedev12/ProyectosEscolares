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

int askDate(){
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

  // usado para transformar fecha completa a segundos desde 1970
  std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  
  // Struct que contiene todos los datos de la fecha-hora
  struct tm dateStruct;
  
  // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
  time_t date;
  
  // tranforma fecha completa a segundos desde 1970
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = std::stoi(seg);
  dateStruct.tm_min = std::stoi(min);
  dateStruct.tm_hour = std::stoi(hora);
  dateStruct.tm_mday = std::stoi(dia);
  
  // Agregado para resolver problema de compatibilidad en Windows
  dateStruct.tm_isdst = 0;
  
  for (size_t i=0; i < meses.size(); i++) {
    
    if (meses[i] == mes)
    
      dateStruct.tm_mon = i;
  }
  
  dateStruct.tm_year = 2022 - 1900;  // Asumimos el año 2022
  
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct); 

  return date;
}

int main() {

  Bitacora myBitacora;
  myBitacora.lecturaDatos("bitacora.txt");
  myBitacora.sortByDate();
  //myBitacora.print();
  
  //cout << "Ejemplo de formato: Jun 13 01:25:12" << endl;
  //cout << "Ingrese primera fecha: ";
  int date1 = askDate();
  
  //cout << "Ingrese segunda fecha: ";
  int date2 = askDate();

  // Los índices en los que están las fechas
  // -1 si no se encuentra
  int date1Index = myBitacora.findByDate(date1);
  int date2Index = myBitacora.findByDate(date2);
  

  if (date1Index < 0){
    cout << "No es encontró la primera fecha" << endl;
    return 0;
  }

  if (date2Index < 0){
    cout << "No es encontró la segunda fecha" << endl;
    return 0;
  }

  myBitacora.printInDateRange(date1Index, date2Index);
  
  /*
  *  Esta última parte es para generar el txt de toda la bitácora ordenada,
  *  la comenté porque tarda bastante y sólamente hace falta hacerla una vez
  */

  /*
  // Escribiendo la bitácora ordenada
  // Creando el archivo para escribir
  std::ofstream outputFile("bitacora_ordenada.txt", std::ofstream::out);

  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open())
  {
    //store array contents to text file
    for (int i = 0; i < myBitacora.getListaRegistros().size(); i++) {
      outputFile << myBitacora.getListaRegistros()[i].getAll() << "\n";
    }
    outputFile.close();
  }
  else cout << "Hubo un problema abriendo el archivo de salida" << endl;  
  */

  
  return 0;
}
