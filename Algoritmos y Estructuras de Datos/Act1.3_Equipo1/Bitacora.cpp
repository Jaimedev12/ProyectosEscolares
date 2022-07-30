#include <iostream>
#include "Bitacora.h"

Bitacora::Bitacora() {
  listaRegistros.resize(0);
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
}

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
      listaRegistros.push_back(tmpReg);
    }
    inputFile.close();
  }
}

void Bitacora::print() {
  
  for (int i = 0; i < (int)listaRegistros.size() - 1; i++) {
  
    std::cout << listaRegistros[i].getAll() << std::endl; 
  }
}

void Bitacora::printInDateRange(int beg, int end){
  for (int i = beg; i <= end; i++) {
    std::cout << listaRegistros[i].getAll() << std::endl; 
  }
}

// Complejidad: O(n/2 + n/2 + n) = O(2n) = O(n)
void merge(vector<Registro> &vector, int low, int medio, int high){
  
  int i, j, k; // O(1)
  
  int n1 = medio - low + 1; // O(1)
  int n2 = high - medio; // O(1)
  
  std::vector<Registro> L(n1); // O(1)
  std::vector<Registro> R(n2); // O(1)

  for( i = 0; i < n1; i++) // Se repite n/2 veces
    L[i] = vector[low + i]; // O(1)
  
  for( j = 0; j < n2; j++) // Se repite n/2 veces
    R[j] = vector[medio + 1 + j]; // O(1)

  i = j = 0; // O(1)
  k = low; // O(1)

  // Entre los 3 whiles, se hacen n ciclos
  while(i < n1 && j < n2){
    
    if(L[i] < R[j]){ // O(1)
      vector[k] = L[i]; // O(1)
      i++; // O(1)
    }
    else{
      vector[k] = R[j]; // O(1)
      j++; // O(1)
    }
    k++; // O(1)
  }

  while(i < n1){
    vector[k] = L[i]; // O(1)
    i++; // O(1)
    k++; // O(1)
  }
  
  while(j < n2){
    vector[k] = R[j]; // O(1)
    j++; // O(1)
    k++; // O(1)
  }
}

// Complejidad: O((log n) * n) = O(n log n)
void mergeSort(vector<Registro> &vector, int low, int high){
  if( low < high){ // O(1)
    int medio = (low + high) / 2; // O(1)

    //Ordena recursivamente las dos mitades
    // Complejidad de la recursividad es 2*T(n/2) y como n solamente puede ser dividido entre 2
    // log2 n veces, podemos concluír que la complejidad de esta parte es O(log n)
    mergeSort(vector, low, medio);
    mergeSort(vector, medio + 1, high); 

    //Fusiona las dos mitades 
    merge(vector, low, medio, high); // O(n)
  } 
}

void Bitacora::sortByDate(){
  mergeSort(listaRegistros, 0, listaRegistros.size() - 1);
}

int Bitacora::findByDate(int key){
  
  /*
  *  Básicamente una implementación de Binary Search
  */
  
  int low = 0; // O(1)
  int high = listaRegistros.size()-1; // O(1)
  int mid = 0; // O(1)

  // Se repite log2 de n veces, ya que la muestra se reduce a la mitad cada vez
  while (low <= high){
    
    mid = low + (high-low)/2; // O(1)
    
    if (key == stoi(listaRegistros[mid].getDate())) return mid; // O(1)
    
    else if (key < stoi(listaRegistros[mid].getDate())) high = mid-1; // O(1)
    
    else low = mid+1; // O(1)
  } 
  
  return -1; // O(1)
}

vector<Registro> Bitacora::getListaRegistros(){
  return listaRegistros;
}

