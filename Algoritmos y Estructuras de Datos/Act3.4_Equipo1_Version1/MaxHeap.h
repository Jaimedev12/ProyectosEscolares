#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class MaxHeap {
  private:
    std::vector<T> data;// contiene los elementos del heap
    int maxCapacity; // capacidad maxima del heap
    int numElements; // numero de elementos actualmente en el heap
    int parent(int i);
    int left(int i);
    int right(int i);
    void heapify_down(int i);   

  public:
    MaxHeap();
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    std::vector<T> getVector();
    int getCapacity();
    int getNumElements();
    T getData(int i);
    void setCapacity(int capacity);
    void print();
    void push(T key);
    T top();
    void pop();

    //void heapSort();
};

// Complejidad: O(1)
template<class T>
MaxHeap<T>::MaxHeap(){
  std::cout << " ---> Creando un MaxHeap por default: " << this << std::endl;
  numElements = 0; // O(1)
  maxCapacity = 1000000; // O(1)
  data.resize(0); // O(1)
}


// Complejidad: O(1)
template <class T>
MaxHeap<T>::MaxHeap(int capacity) {
  std::cout << " ---> Creando un MaxHeap vacio: " << this << std::endl;
  numElements = 0; // O(1)
  maxCapacity = capacity; // O(1)
  data.resize(maxCapacity); // O(1)
}


// Complejidad: O(1)
template <class T>
MaxHeap<T>::~MaxHeap() {
  std::cout << " ---> Liberando la memoria del MaxHeap: " << this << std::endl;
  numElements = 0; // O(1)
  maxCapacity = 0; // O(1)
  data.clear(); // O(1)
}


// Complejidad: O(1)
template <class T>
bool MaxHeap<T>::isEmpty() {
  return (numElements == 0); // O(1)
}


// Complejidad: O(1)
template <class T>
std::vector<T> MaxHeap<T>::getVector(){
  return data;
}


// Complejidad: O(1)
template <class T>
int MaxHeap<T>::getCapacity() {
  return maxCapacity;
}


// Complejidad: O(1)
template <class T>
int MaxHeap<T>::getNumElements() {
  return numElements; // O(1)
}


// Complejidad: O(1)
template <class T>
T MaxHeap<T>::getData(int i) {
  return data[i]; // O(1)
}

template<class T>
void MaxHeap<T>::setCapacity(int capacity) {
  maxCapacity = capacity;
}

// Complejidad: O(1)
template <class T>
int MaxHeap<T>::parent(int i) {
  return (i-1)/2; // O(1)
}


// Complejidad: O(1)
template <class T>
int MaxHeap<T>::left(int i) {
  return (2*i + 1); // O(1)
}


// Complejidad: O(1)
template <class T>
int MaxHeap<T>::right(int i) {
  return (2*i + 2); // O(1)
}


// Complejidad: O(n)
template <class T>
void MaxHeap<T>::print() {
  std::cout << "El contenido del MaxHeap es: " << std::endl;
  for (int i = 0; i < numElements; i++) { // Se repite n veces
    std::cout << data[i] << " "; // O(1)
  }
  std::cout << std::endl; // O(1)
}


// Complejidad: O(logn)
template <class T>
void MaxHeap<T>::push(T key) {
  if (numElements == maxCapacity) {
    throw std::out_of_range("Overflow: no se puede insertar la llave"); // O(1)
  }
  // Insertar la nueva llave al final del vector
  int i = numElements; // O(1)
  data.push_back(key); // O(1)
  numElements++; // O(1)
  
  // Reparar las propiedades del MaxHeap
  // Como máximo se repite log2n ya que tendría que recorrer toda la altura del árbol
  while (i != 0 && data[parent(i)] < data[i]) { 
    std::swap(data[i], data[parent(i)]); // O(1)
    i = parent(i);// O(1)
  }
}


// Complejidad: O(1)
template<class T> 
T MaxHeap<T>::top(){
  if(numElements == 0){
    throw  std::out_of_range("La lista esta vacia"); // O(1)
  }
  else
    return data[0]; // O(1)
}


// https://www.techiedelight.com/min-heap-max-heap-implementation-c/
// Complejidad: 1*T(n/2) + O(1) = O(log n)
template<class T> 
void MaxHeap<T>::heapify_down(int i) {
  int l = left(i); // O(1)
  int r = right(i); // O(1)

  int largest = i; // O(1)

  if (l < numElements && data[l] > data[i]) {
    largest = l; // O(1)
  }

  if (r < numElements && data[r] > data[largest]) {
    largest = r; // O(1)
  }

  if (largest != i)
  {
    std::swap(data[i], data[largest]); // O(1)
    heapify_down(largest); //  <---- 1
  }
}


// Complejidad: O(logn)
template <class T> 
void MaxHeap<T>::pop() {

  if(numElements == 0){
    throw  std::out_of_range("La lista esta vacia"); // O(1)
  }
  
  // Intercambiamos el último elemento de la lista con la raíz
  data[0] = data[numElements-1]; // O(1)

  // Eliminamos físicamente el último elemento del vector (última hoja)
  data.pop_back(); // O(1)
  numElements--; // O(1)

  // Reparar las propiedades del MaxHeap
  heapify_down(0); // O(logn)
}


/*
template<class T>
void MaxHeap<T>::heapSort(){
  // Build heap (rearrange vector)
  for (int i = numElements / 2 - 1; i >= 0; i--)
    heapify_down(i);

  // One by one extract an element 
  // from heap
  for (int i = numElements - 1; i > 0; i--) {
      
    // Move current root to end
    std::swap(data[0], data[i]);

    // call max heapify on the reduced heap
    heapify_down(0);
  }
}
*/



#endif // _MAXHEAP_H_
