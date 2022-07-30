#include <iostream>
#include <string>
#include <sstream>
#include "Bitacora.h"

// Complejidad: O(1)
Bitacora::Bitacora() {
  listaDatos.resize(0); // O(1)
}

// Complejidad: O(1)
Bitacora::~Bitacora() {
  listaDatos.clear();  // O(1)
}


// Complejidad: O(n)
void Bitacora::lecturaDatos(std::string fileName) { //almacena los datos en un vector que posteriormente se ordenara y se usará para crear el MaxHeap
  
  std::string month, day, hour, minute, second, ipAdd, port, message;// O(1)
   
  std::ifstream inputFile(fileName); // O(1)
  
  if (!inputFile.good()) {
    inputFile.close(); // O(1)
    throw std::invalid_argument("File not found"); // O(1)
  }
  else {
    while (!inputFile.eof()) { // Se repite n veces
      // to-do validar que la longitud de month sea mayor a cero
      std::getline(inputFile, month, ' ');  // O(1)
      std::getline(inputFile, day, ' ');    // O(1)
      std::getline(inputFile, hour, ':');   // O(1)
      std::getline(inputFile, minute, ':'); // O(1)
      std::getline(inputFile, second, ' '); // O(1)
      std::getline(inputFile, ipAdd, ':');  // O(1)
      std::getline(inputFile, port, ' ');   // O(1)
      std::getline(inputFile, message);     // O(1)
      
      // crear un objeto de la clase Registro
      Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message); // O(n)
      // agragar el objeto al vector
      listaDatos.push_back(tmpReg); // O(1)
    }
    inputFile.close(); // O(1)
  }
}


// Complejidad: T(n/2) + O(1) = O(log n) 
// https://www.geeksforgeeks.org/heap-sort/
void Bitacora::heapify(vector<Registro> &vector, int heapSize, int index) {
  // Initialize largest as root
  int largest = index;  // O(1)
    
  // left = 2*i + 1
  int left = 2 * index + 1;  // O(1)
    
  // right = 2*i + 2
  int right = 2 * index + 2;  // O(1)
  
  // If left child is larger than root
  if (left < heapSize && vector[left] > vector[largest])
    largest = left;   // O(1)
  
  // If right child is larger than largest 
  // so far
  if (right < heapSize && vector[right] > vector[largest])
    largest = right;  // O(1)
  
  // If largest is not root
  if (largest != index) {
    std::swap(vector[index], vector[largest]);   // O(1)
 
  // Recursively heapify the affected 
  // sub-tree
  heapify(vector, heapSize, largest); // O(log n)
  }
}

// Complejidad: O(log n + nlog n) = O(nLogn)
void Bitacora:: heapSort(vector<Registro> &vector, int heapSize){
  // Build heap (rearrange vector)
  for (int i = heapSize / 2 - 1; i >= 0; i--) // Se repite n veces
    heapify(vector, heapSize, i); // O(log n)
  
  // One by one extract an element from heap
  for (int i = heapSize - 1; i > 0; i--) { // Se repite n veces
        
  // Move current root to end
  std::swap(vector[0], vector[i]);   // O(1)
  
  // call max heapify on the reduced heap
  heapify(vector, i, 0); // O(log n)
  }
}

// Complejidad:
void Bitacora::sortByIp(){
  heapSort(listaDatos, listaDatos.size()); //  O(nlog n)
  exportToTxt("bitacora_ordenada.txt");
}


// Complejidad:
void  Bitacora::contabilizarIP(){ 
  //Cuenta repeticiones de ip, agrega al archivo solo ip y repeticiones, hace push de ip y repeticiones a MaxHeap usando las repeticiones como prioridad.
  int contador = 0; // O(1)
  int i = 0;   // O(1)
  Registro *actual = &listaDatos[0];      // O(1)
  Registro *siguiente = &listaDatos[0];   // O(1)
  listaIps.setCapacity(listaDatos.size());
  
//  std::cout << "      IP           Repeticiones   " << std::endl;
      
  std::ofstream file;   // O(1)
  file.open("listaDeIps.txt");   // O(1)
  
  while (i < listaDatos.size()){ //O(n)
    while (actual->getIpObject().getNumericIp() == siguiente->getIpObject().getNumericIp()){  // O(n)
      contador++;   // O(1)
      //std::cout << siguiente->getIpObject().getIpString()  << "      " << contador << std::endl;
      i++;   // O(1)
      siguiente++;   // O(1)
    }
    
    actual->ipObject.setRepeticiones(contador) ;   // O(1)
    //std::cout << actual->getIpObject().getIpString()  << "            " << actual->ipObject.getRepeticiones() << std::endl;
  // file << actual->getAll() <<  "      " << actual->ipObject.getRepeticiones() << std::endl;
    file << actual->getIpObject().getIpString()  << " " << actual->getIpObject().getRepeticiones() << "\n"; //
    
    Ip tmpIp(actual->getIpObject().getIpString(),actual->getIpObject().getRepeticiones()); //O(n)
    listaIps.pushIp(tmpIp); // O(logn)
    
//    std::cout << std::endl;
    actual = siguiente;   // O(1)
    contador = 0;   // O(1)
  }
  file.close();   // O(1)
  HeapExportTxt("prioridadDeIps.txt");  
}


// Complejidad:
/*Utilizando la estructura de datos del punto anterior encuentra las cinco IPs con más accesos. Despliega en pantalla el resultado con los pares (IP, accesos totales) y Almacena el resultado del ordenamiento en un archivo llamado "ips_con_mayor_acceso.txt".*/
void Bitacora::topFive(){
//  printHeap();
  std::cout << std::endl << "      IP           Repeticiones   " << std::endl;  
  
  std::ofstream outputFile("ips_con_mayor_acceso.txt", std::ofstream::out); //  O(1)
  if (outputFile.is_open()){
    for (int i=1 ; i < 6; i++){ 
      outputFile << listaIps.top().getIpString()<< "          " << listaIps.top().getRepeticiones()<< std::endl;
      std::cout  << listaIps.top().getIpString()<< "          " << listaIps.top().getRepeticiones() << std::endl<< std::endl;
      listaIps.popIp();
 //     printHeap();
    }
    outputFile.close(); // O(1)
  } 
  else {
    std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
  }
}


// Complejidad: O(n)
void Bitacora::printVector() {
  for (int i = 0; i < (int)listaDatos.size(); i++) { // O(n)
    std::cout << listaDatos[i].getAll() << std::endl; 
  }
}

// Complejidad:
void Bitacora::printHeap() {
  std::cout << std::endl << "Los elementos de MaxHeap son: " << std::endl;
  for (int i = 0; i < 10 ; i++) { //listaIps.getNumElements()
    std::cout << listaIps.getData(i).getIpString() << "      " << listaIps.getData(i).getRepeticiones() << std::endl; // O(1)
  }
}


// Complejidad:
void Bitacora::exportToTxt(std::string fileString){ // exporta vector a archivo 
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open()) {
    //store vector contents to text file
    for (int i = 0; i < listaDatos.size(); i++) { // Se repite n veces
    //outputFile << listaDatos[i].getAll() << "      " << listaDatos[i].ipObject.getRepeticiones() << std::endl; 

      outputFile << listaDatos[i].getAll() << "\n"; 
    }
    
    outputFile.close(); // O(1)
  }
  else std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
}


// Complejidad: O(n)
void Bitacora::HeapExportTxt(std::string fileString){ // exporta MaxHeap a archivo indicado
  std::ofstream outputFile(fileString, std::ofstream::out); //  O(1)
//  DLLNode<Registro>* ptr = listaRegistros.getHead(); // O(1)

  // Verificando si el archivo se abrió correctamente
  if (outputFile.is_open()) {
    //store array contents to text file
    for (int i = 0; i < listaIps.getNumElements(); i++) { // Se repite n veces
    outputFile << listaIps.getData(i).getIpString()  << " " << listaIps.getData(i).getRepeticiones() << std::endl; 
    }
    outputFile.close(); // O(1)
  }
  else std::cout << "Hubo un problema abriendo el archivo de salida" << std::endl; // O(1)
}

// Complejidad: O(1)
MaxHeap<Ip> Bitacora::getListaIps(){
  return listaIps; //O(1)
}

/* métodos de entregas anteriores
void Bitacora::printInDateRange(int beg, int end){
  for (int i = beg; i <= end; i++) {
    std::cout << listaRegistros[i].getAll() << std::endl; 
  }
}

// Complejidad: O(n/2 + n/2 + n) = O(2n) = O(n)
void merge(MaxHeap<Registro> &lista, int low, int medio, int high){
  int i, j, k; // O(1)
  int n1 = medio - low + 1; // O(1)
  int n2 = high - medio; // O(1)
  std::vector<Registro> L(n1); // O(1)
  std::vector<Registro> R(n2); // O(1)
  for( i = 0; i < n1; i++) // Se repite n/2 veces
    L[i] = lista[low + i]; // O(1)
  
  for( j = 0; j < n2; j++) // Se repite n/2 veces
    R[j] = lista[medio + 1 + j]; // O(1)

  i = j = 0; // O(1)
  k = low; // O(1)
  
  // Entre los 3 whiles, se hacen n ciclos
  while(i < n1 && j < n2){
    
    if(L[i] < R[j]){ // O(1)
      lista[k] = L[i]; // O(1)
      i++; // O(1)
    }
    else{
      lista[k] = R[j]; // O(1)
      j++; // O(1)
    }
    k++; // O(1)
  }

  while(i < n1){
    lista[k] = L[i]; // O(1)
    i++; // O(1)
    k++; // O(1)
  }
  
  while(j < n2){
    lista[k] = R[j]; // O(1)
    j++; // O(1)
    k++; // O(1)
  }
}

// Complejidad: O((log n) * n) = O(n log n)
void mergeSort(MaxHeap<Registro> &lista, int low, int high){
  if( low < high){ // O(1)
    int medio = (low + high) / 2; // O(1)
    //Ordena recursivamente las dos mitades
    // Complejidad de la recursividad es 2*T(n/2) y como n solamente puede ser dividido entre 2
    // log2 n veces, podemos concluír que la complejidad de esta parte es O(log n)
    mergeSort(lista, low, medio);
    mergeSort(lista, medio + 1, high); 
    //Fusiona las dos mitades 
    merge(lista, low, medio, high); // O(n)
  } 
}

void Bitacora::sortByDate(){
  mergeSort(listaRegistros, 0, listaRegistros.getNumElements() - 1);
}


int Bitacora::findByDate(int key){
  //  Básicamente una implementación de Binary Search
  int low = 0; // O(1)
  int high = listaRegistros.getNumElements()-1; // O(1)
  int mid = 0; // O(1)
  // Se repite log2 de n veces,[i] ya que la muestra se reduce a la mitad cada vez
  while (low <= high){
    mid = low + (high-low)/2; // O(1)
    if (key == stoi(listaRegistros[mid].getDate())) return mid; // O(1)
    else if (key < stoi(listaRegistros[mid].getDate())) high = mid-1; // O(1)
    else low = mid+1; // O(1)
  } 
  return -1; // O(1)
}
*/


