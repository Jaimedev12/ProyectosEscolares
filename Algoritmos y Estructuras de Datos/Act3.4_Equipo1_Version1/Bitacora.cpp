#include <iostream>
#include <string>
#include <sstream>
#include "Bitacora.h"

Bitacora::Bitacora() {
  listaRegistros.resize(0);
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
}

// Complejidad: O(nlogn)
void Bitacora::lecturaDatos(std::string fileName) { //almacena los datos en un vector que posteriormente se ordenara y se usará para crear el MaxHeap
  
  std::string month, day, hour, minute, second, ipAdd, port, message; // O(1)
   
  std::ifstream inputFile(fileName); // O(1)
  
  if (!inputFile.good()) {
    inputFile.close(); // O(1)
    throw std::invalid_argument("File not found"); // O(1)
  }
  else {
    while (!inputFile.eof()) { // Se repite n veces
      // to-do validar que la longitud de month sea mayor a cero
      std::getline(inputFile, month, ' '); // O(1)
      std::getline(inputFile, day, ' '); // O(1)
      std::getline(inputFile, hour, ':'); // O(1) 
      std::getline(inputFile, minute, ':'); // O(1)
      std::getline(inputFile, second, ' '); // O(1)
      std::getline(inputFile, ipAdd, ':'); // O(1)
      std::getline(inputFile, port, ' '); // O(1)
      std::getline(inputFile, message); // O(1)
      
      // crear un objeto de la clase Registro
      Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message);

      // Agregamos registro al heap
      heapRegistros.push(tmpReg); // O(logn)
    }
    inputFile.close(); // O(1)
  }
}


// Complejidad: O(nlog n)
void Bitacora::sortRegistrosByIp(){

  while (!heapRegistros.isEmpty()){ // Se repite n veces
    listaRegistros.push_back(heapRegistros.top()); // O(1)
    heapRegistros.pop(); // O(log n);
  }
  
}

void Bitacora::sortDistinctIpsByRepeticiones() {
  while (!heapIps.isEmpty()) { // Se repite n veces
    listaIps.push_back(heapIps.top()); // O(1)
    heapIps.pop(); // O(log n);
  }
}

//Complejidad: O(n*n) = O(nlogn)
void  Bitacora::contabilizarIP(){ //Cuenta repeticiones de ip y las agraga a listaIps
  int contador = 0; //O(1) 
  int i = 0; //O(1)
  Registro *actual = &listaRegistros[0]; //O(1)
  Registro *siguiente = &listaRegistros[0]; //O(1)
      
  while (i < listaRegistros.size()){ // Todo el ciclo se repite n veces
    while (actual->getIpObject() == siguiente->getIpObject()){ 
      contador++; //O(1)
      i++; //O(1)
      siguiente++; //O(1)
    }
    
    actual->ipObject.setRepeticiones(contador) ; //O(1)
    
    Ip tmpIp(actual->getIpObject().getIpString(),actual->getIpObject().getRepeticiones()); //O(1)
    DistinctIp tmpDistIp(tmpIp); //O(1)
    heapIps.push(tmpDistIp); // O(logn)
    
    actual = siguiente; //O(1)
    contador = 0;  //O(1)
  }
}

// Complejidad: O(n)
void Bitacora::exportRegistrosToTxt(std::string fileString){ // exporta vector a archivo 
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open()) {
    //store vector contents to text file
    for (int i = 0; i < listaRegistros.size(); i++) { // Se repite n veces
      outputFile << listaRegistros[i].getAll() << "\n"; 
    }
    
    outputFile.close(); // O(1)
  }
  else std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
}


// Complejidad: O(n)
void Bitacora::exportIpsToTxt(std::string fileString){
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
  
  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open()) {
    
    //store vector contents to text file
    for (int i = 0; i < listaIps.size(); i++) { // Se repite n veces
      outputFile << listaIps[i].getIp().getIpString() << "\t"
        << listaIps[i].getIp().getRepeticiones() << std::endl;
    }
    
    outputFile.close(); // O(1)
  }
  else std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
}

// Complejidad: O(n)
void Bitacora::exportIpsConMayorAcceso(int n, std::string fileString) {
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
  
  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open()) { 
    
    //store vector contents to text file
    for (int i = 0; i < n; i++) { // Se repite n veces
      outputFile << listaIps[i].getIp().getIpString() << "\t"
        << listaIps[i].getIp().getRepeticiones() << std::endl;
    }
    outputFile.close(); // O(1)
  }
  else std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
}

// Complejidad O(n)
void Bitacora::printIpsConMayorAcceso(int n){
  for (int i = 0; i < n; i++) { // Se repite n veces
    std::cout << listaIps[i].getIp().getIpString() << "\t\t"
      << listaIps[i].getIp().getRepeticiones() << std::endl;
  }
}

// Complejidad: O(1)
vector<Registro> Bitacora::getListaRegistro() {
  return listaRegistros; //O(1)
}
