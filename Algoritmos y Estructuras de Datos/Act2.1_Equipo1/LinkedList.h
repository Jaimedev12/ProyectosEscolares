#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"
#include <iostream>

template <class T>
class LinkedList {
  private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

  public:
    LinkedList();
    ~LinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int posicion);
    T getData(int position);
    void updateData(T value, T newValue);
    void updateAt(int posicion, T newValue);
    int findData(T value);
    void operator=(LinkedList<T> &other);  // se llama asi en el main:  lista1 = lista2
};

//Complejoidad: O(1)
template<class T> 
LinkedList<T>::LinkedList() {
  std::cout << "--- Creando una lista vacia --- " << &head << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

//Complejida: O(n)
template<class T>
LinkedList<T>::~LinkedList() {
  std::cout << "--- Liberando memoria de la lista --- " << &head << std::endl;
  
  Node<T> *prev, *q; //O(1)
  prev = head; //O(1)

  
  while (prev != nullptr) { //Se repite hasta n veces = O(n)
    q = prev->next; //O(1)
    delete prev; //O(1)
    prev = q; //O(1)
  }
  
  head = nullptr;  //O(1)
  tail = nullptr;  //O(1)
  numElements = 0;  //O(1)
}


// Complejidad: O(1)
template<class T>
int LinkedList<T>::getNumElements() {
  return numElements; //O(1)
}


// Complejidad: O(n)  
template<class T>
void LinkedList<T>::printList() {
  Node<T> *ptr = head;  //O(1)

  
  while (ptr != nullptr) { //Se repite hasta n veces = //O(n)
    std::cout << ptr->data << " ";  //O(1)
    ptr = ptr->next; //O(1)
  }
  
  std::cout << std::endl;
}


// Complejidad: O(1)
template<class T>
void LinkedList<T>::addFirst(T value) {
  
  // creando un nuevo nodo de la lista
  Node<T> *newNode = new Node<T>(value);  //O(1)
  
  // Si la lista esta vacia if(head == nullptr)
  
  if (numElements == 0) { //O(1)
    head = newNode; //O(1)
    tail = newNode; //O(1)
  } 
  else {
    newNode->next = head; //O(1)
    head = newNode; //O(1)
  }
  numElements++; //O(1)
}


// Complejidad: O(1)
template<class T>
void LinkedList<T>::addLast(T value) {
  
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    addFirst(value); //O(1)
  }
  else {
    // creando un nuevo nodo de la lista
    Node<T> *newNode = new Node<T>(value); //O(1)
    tail->next = newNode; //O(1)
    tail = newNode; //O(1)
    numElements++; //O(1)
  }
}


// Complejidad: while = O(n)
template<class T>
bool LinkedList<T>::deleteData(T value) {
  bool estado = false; //O(1)
  
  // Si la lista esta vacia
  if (numElements == 0) {
    return estado; //O(1)
  }
  else {
   
    Node<T> *p = head; //O(1)
    Node<T> *prev = nullptr; //O(1)
   
    // buscar value en la lista
    while (p != nullptr && p->data != value) { //Se repite hasta n veces
      prev = p; //O(1)
      p = p->next; //O(1)
    }
    
    // si no existe value en la lista
    if (p == nullptr)
      return estado; //O(1)
    
    // Si debe borrarse el primer elemento de la lista
    if (p == head) {
      head = p->next; //O(1)
      
    } else if (p->next == nullptr) { // borrar ultimo en la lista
      
      prev->next = nullptr; //O(1)
      tail = prev; //O(1)
    } else {
      prev->next = p->next; //O(1)
    }
    delete p; //O(1)
    numElements--; //O(1)
    estado = true; //O(1)
    return estado; //O(1)
  }
}


// Complejidad: O(n)
template<class T>
bool LinkedList<T>::deleteAt(int position) {
  
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango"); //O(1)
  }
  else if (position == 0) { // Si debe borrarse el primer elemento
    
    Node<T> *p = head; //O(1)
    
    // Si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr) {
      head = nullptr; //O(1)
      tail = nullptr; //O(1)
    }
    else {
      head = p->next; //O(1)
    } 
    delete p; //O(1)
    numElements--; //O(1)
    return true; //O(1)
  }
  else { // Si la lista contiene mas de un nodo
    
    Node<T> *p = head, *q = nullptr; //O(1)
    int index = 0; //O(1)
    
    // Se busca el indice del elemento a borrar
    while (index != position) { //Se repite hasta n veces 
      q = p; //O(1)
      p = p->next; //O(1)
      index++; //O(1)
    }
    
    // Si debe borrarse el último elemento
    if (p->next == nullptr) {
      q->next = nullptr; //O(1)
      tail = q; //O(1)
    }
    else { // Cualquier otro elemento en medio de la lista 
      q->next = p->next; //O(1)
    }
    
    delete p; //O(1)
    numElements--; //O(1)
    return true; //O(1)
  }
}


// Complejidad: O(n)
template<class T>
T LinkedList<T>::getData(int position) {
  
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango"); //O(1)
  }
  else {
    
    if (position == 0)
      return head->data; //O(1)
    
    Node<T> *p = head; //O(1)
    int index = 0; //O(1)
    
    while (p != nullptr) { //Se repite hasta n veces 
      
      if (index == position)
        return p->data; //O(1)
        index++; //O(1)
        p = p->next; //O(1)
    }
    return {};
  }
}


// Complejidad: O(n)
template<class T>
void LinkedList<T>::updateData(T value, T newValue) {
  
  if (numElements > 0) {
    
    Node<T> *p = head; //O(1)
    Node<T> *prev = nullptr; //O(1)
    
    // buscar value en la lista
    while (p != nullptr && p->data != value) { //Se repite hasta n veces
      prev = p; //O(1)
      p = p->next; //O(1)
    }
    
    // si existe value en la lista
    if (p != nullptr) //O(1)
      p->data = newValue; //O(1)
    else
      throw std::out_of_range("No se encontró el valor en la lista"); //O(1)
  }  
}


// Complejidad: O(n)
template<class T>
void LinkedList<T>::updateAt(int posicion, T newValue){
  
  if (posicion < 0 || posicion >= numElements) {
    throw std::out_of_range("Indice fuera de rango"); //O(1)
  }
  else {
    
    Node<T> *p = head; //O(1)
    int index = 0; //O(1)
    
    while (p != nullptr) { //Se repite hasta n veces 
      
      if (index == posicion) //O(1)
        p->data = newValue; //O(1)
      index++; //O(1)
      p = p->next; //O(1)
    }
  }
}


// Complejidad: 0(n)
template<class T>
int LinkedList<T>::findData(T value){
  
  if (numElements > 0) { //O(n)
    
    Node<T> *p = head; //O(1)
    Node<T> *previo = nullptr; //O(1)
    int index = 0; //O(1)
    
    // buscar value en la lista
    while (p != nullptr && p->data != value) { //Se repite hasta n veces
      previo = p; //O(1)
      p = p->next; //O(1)
      index++; //O(1)
    }
    
    // si existe value en la lista
    if (p != nullptr) //O(1)
      return index; //O(1)
    else
      return -1; //O(1)
      throw std::out_of_range("No se encontró el valor en la lista"); //O(1)
      
  }  
}



// Complejidad: O(n + n) = O(2n) = O(n)
template<class T>
void LinkedList<T>::operator = (LinkedList<T> &other) {

  Node<T> *p = head, *prev = nullptr; // O(1)
  
  // Vaciar los objetos que ya tenemos en nuestra lista
  // Complejidad del ciclo: O(n)
  while(numElements > 0){ // Se repite n veces
    prev = p; // O(1)
    p = p->next; // O(1)
    delete prev; // O(1)
    numElements--; // O(1)
    if (numElements == 0){ // O(1)
      head = nullptr; // O(1)
      tail = nullptr; // O(1)
    }
  }

  // Copiar los valores de other a nuestra lista
  // Complejidad del ciclo: O(n)
  for (int i = 0; i < other.numElements; i++){ // Se repite n veces

    // Para el primer elemento de la lista
    if (numElements == 0){ // O(1)
      addFirst(other.getData(i)); // O(1)
    } else { // Para el resto de elementos
      addLast(other.getData(i)); // O(1)
    }
    numElements++; // O(1)
  }

}


#endif  // _LINKEDLIST_H_