#include <iostream>
#include "Bitacora.h"

Bitacora::Bitacora() { }

void Bitacora::lecturaDatos(std::string fileName) {
  
  std::string month, day, hour, minute, second, ipAdd, port, message;
  
  std::ifstream inputFile(fileName);
  
  if (!inputFile.good()) {
    
    inputFile.close();
    
    throw std::invalid_argument("File not found");
  }
  else {
    
    while (!inputFile.eof()) {
      // to-do validar que la longitud de month sea mayor a cero
      std::getline(inputFile, month, ' ');
      std::getline(inputFile, day, ' ');
      std::getline(inputFile, hour, ':');
      std::getline(inputFile, minute, ':');
      std::getline(inputFile, second, ' ');
      std::getline(inputFile, ipAdd, ':');
      std::getline(inputFile, port, ' ');
      std::getline(inputFile, message);
      
      // crear un objeto de la clase Registro
      Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message);
      
      // agragar el objeto al vector
      listaRegistros.addLast(tmpReg);
    }
    inputFile.close();
  }
}


// Complejidad: O(n)
void Bitacora::print() {
  DLLNode<Registro> *ptr = listaRegistros.getHead(); // O(1)
  // Complejidad del ciclo: O(n)
  while (ptr != nullptr) { // Se repite n veces  <----
    std::cout << ptr->data.getAll() << std::endl; // O(1)
    ptr = ptr->next; // O(1)
  }
  std::cout << std::endl; // O(1)
}


// Complejidad: O(n)
void Bitacora::exportTxt(std::string fileString){
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
  DLLNode<Registro>* ptr = listaRegistros.getHead(); // O(1)

  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open()) {
    //store array contents to text file
    while (ptr != nullptr) { // Se repite n veces  <----
    outputFile << ptr->data.getAll() << std::endl; // O(1)
    ptr = ptr->next; // O(1)
  }
    outputFile.close(); // O(1)
  }
  else std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
}


// Complejidad: O(n)
void Bitacora::printInDateRange(DLLNode<Registro>* beg, DLLNode<Registro>* end){
  
  if (beg->data > end->data){
    throw std::out_of_range("Fecha de inicio mayor a fecha final"); // O(1)
  }

  while (beg != nullptr && beg->data <= end->data){ // Se repite n veces
    std::cout << beg->data.getAll() << std::endl; // O(1)
    beg = beg->next; // O(1)
  }
  
}


// Complejidad: O(n)
void Bitacora::exportInRange(DLLNode<Registro>* beg, DLLNode<Registro>* end, std::string fileString){
  
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
  //DLLNode<Registro>* ptr = beg; // O(1)

  if (outputFile.is_open()){
    if (beg->data > end->data){
      throw std::out_of_range("Fecha de inicio mayor a fecha final"); // O(1)
    }
    
    while (beg != nullptr && beg->data <= end->data){ // Se repite n veces
      outputFile << beg->data.getAll() << std::endl; // O(1)
      beg = beg->next; // O(1)
    }
    
    outputFile.close(); // O(1)
  } else {
    std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
  }
}


// Complejidad: O(nlogn)
void Bitacora::sortByDate(){
  listaRegistros.sortMerge(); // O(nlogn)
  //listaRegistros.quickSort(listaRegistros.getHead(), listaRegistros.getTail());
  //mergeSort(listaRegistros, 0, listaRegistros.size() - 1);
}


// Complejidad: O(logn)
DLLNode<Registro>* Bitacora::findByDate(Registro key){
  // Se busca un objeto con esta misma fecha dentro de la lista y se indica si está o no
  return listaRegistros.binarySearch(key); // O(logn)

}


// O(1)
DoubleLinkedList<Registro> Bitacora::getListaRegistros(){
  return listaRegistros; // O(1)
}

  