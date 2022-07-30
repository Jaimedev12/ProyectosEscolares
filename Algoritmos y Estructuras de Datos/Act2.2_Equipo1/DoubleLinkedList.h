#ifndef _DoubleLinkedList_H_
#define _DoubleLinkedList_H_

#include "DLLNode.h"
#include <iostream>

template <class T>
class DoubleLinkedList {
  private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int numElements;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
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
    void operator = (DoubleLinkedList<T> &other);
    void swap ( T* valueA, T* valueB );
    DLLNode<T>* particion(DLLNode<T> *inicio, DLLNode<T> *fin);
    void quickSort(DLLNode<T> *inicio, DLLNode<T> *fin);
    void sort();
    void invert();
    DoubleLinkedList<T> getReversedSublist(int inicio, int fin);
};

// Complejidad: O(1)
template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "--- Creando una lista doblemente ligada vacia --- " << &head << std::endl; // O(1)
  head = nullptr; // O(1)
  tail = nullptr; // O(1)
  numElements = 0; // O(1)
}

// Complejidad: O(n)
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  std::cout << "--- Liberando memoria de la lista doblemente ligada --- " << &head << std::endl;
  DLLNode<T> *prev, *q; // O(1)
  prev = head; // O(1)
  // Complejidad del ciclo: O(n)
  while (prev != nullptr) { // Se repite n veces  <----
    q = prev->next; // O(1)
    delete prev; // O(1)
    prev = q; // O(1)
  }
  head = nullptr; // O(1)
  tail = nullptr; // O(1)
  numElements = 0; // O(1)
}



// Complejidad: O(1)
template<class T>
int DoubleLinkedList<T>::getNumElements() {
  return numElements; // O(1)
}


// Complejidad: O(n)
template<class T>
void DoubleLinkedList<T>::printList() {
  DLLNode<T> *ptr = head; // O(1)
  // Complejidad del ciclo: O(n)
  while (ptr != nullptr) { // Se repite n veces  <----
    std::cout << ptr->data << " "; // O(1)
    ptr = ptr->next; // O(1)
  }
  std::cout << std::endl; // O(1)
}


// Complejidad: O(1)
template<class T>
void DoubleLinkedList<T>::addFirst(T value) {
  // creando un nuevo nodo de la lista
  DLLNode<T> *newDLLNode = new DLLNode<T>(value); // O(1)
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) { // O(1)
    head = newDLLNode; // O(1)
    tail = newDLLNode; // O(1)
  } 
  else {
    newDLLNode->next = head; // O(1)
    head->prev = newDLLNode; // O(1)
    head = newDLLNode; // O(1)
  }
  numElements++; // O(1)
}


// Complejidad: O(1)
template<class T>
void DoubleLinkedList<T>::addLast(T value) {
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) { // O(1)
    addFirst(value); // O(1)
  }
  else {
    // creando un nuevo nodo de la lista
    DLLNode<T> *newDLLNode = new DLLNode<T>(value); // O(1)
    tail->next = newDLLNode; // O(1)
    newDLLNode->prev = tail; // O(1)
    tail = newDLLNode; // O(1)
    numElements++; // O(1)
  }
}


// Complejidad: O(n)
template<class T>
bool DoubleLinkedList<T>::deleteData(T value) {
  bool estado = false; // O(1)
  // Si la lista esta vacia
  if (numElements == 0) { // O(1)
    return estado; // O(1)
  }
  else {
    DLLNode<T> *p = head; // O(1)
    DLLNode<T> *previo = nullptr; // O(1)
    // buscar value en la lista
    // Complejidad del ciclo: O(n)
    while (p != nullptr && p->data != value) { // Se repite n veces en el peor de los  <----
      previo = p; // O(1)
      p = p->next; // O(1)
    }
    // si no existe value en la lista
    if (p == nullptr) // O(1)
      return estado; // O(1)
    // Si debe borrarse el primer elemento de la lista
    if (p == head) { // O(1)
      head = p->next; // O(1)
      if (head != nullptr) // O(1)
        head->prev = nullptr; // O(1)
    } else if (p->next == nullptr) { // borrar ultimo en la lista
      previo->next = nullptr; // O(1)
      tail = previo; // O(1)
    } else { // cualquier otro elemento de la lista
      previo->next = p->next; // O(1)
      p->next->prev = p->prev; // O(1)
    }
    delete p; // O(1)
    numElements--; // O(1)
    estado = true; // O(1)
    return estado; // O(1)
  }
}


// Complejidad: O(n) (Aumenta la complejidad conforme a la variable position)
template<class T>
bool DoubleLinkedList<T>::deleteAt(int position) {
  if (position < 0 || position >= numElements) { // O(1)
    throw std::out_of_range("Indice fuera de rango"); // O(1)
  }
  else if (position == 0) { // Si debe borrarse el primer elemento // O(1)
    DLLNode<T> *p = head; // O(1)
    // Si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr) { // O(1)
      head = nullptr; // O(1)
      tail = nullptr; // O(1)
    }
    else {
      head = p->next; // O(1)
      head->prev = nullptr; // O(1)
    }
    delete p; // O(1)
    numElements--; // O(1)
    return true; // O(1)
  }
  else { // Si position > 0 
    DLLNode<T> *p = head, *q = nullptr; // O(1)
    int index = 0; // O(1)
    // Se busca el indice del elemento a borrar
    // Complejidad del ciclo: O(n)
    while (index != position) { // Se repite "position" veces, (n en el peor de los casos)  <----
      q = p; // O(1)
      p = p->next; // O(1)
      index++; // O(1)
    }
    // Si debe borrarse el último elemento
    if (p->next == nullptr) { // O(1)
      q->next = nullptr; // O(1)
      tail = q; // O(1)
    }
    else { // Cualquier otro elemento en medio de la lista 
      q->next = p->next; // O(1)
      p->next->prev = q; // O(1)
    }
    delete p; // O(1)
    numElements--; // O(1)
    return true; // O(1)
  }
}


// Complejidad: O(n)
template<class T>
T DoubleLinkedList<T>::getData(int position) { // O(1)
  if (position < 0 || position >= numElements) { // O(1)
    throw std::out_of_range("Indice fuera de rango"); // O(1)
  }
  else { // O(1)
    if (position == 0) // O(1)
      return head->data; // O(1)
    DLLNode<T> *p = head; // O(1)
    int index = 0; // O(1)
    // Complejidad del ciclo: O(n)
    while (p != nullptr) { // Se repite n veces  <----
      if (index == position) // O(1)
        return p->data; // O(1)
      index++; // O(1)
      p = p->next; // O(1)
    }
    return {}; // O(1)
  }
}


// Complejidad: O(n)
template<class T>
void DoubleLinkedList<T>::updateData(T value, T newValue) {
  if (numElements > 0) { // O(1)
    DLLNode<T> *p = head; // O(1)
    DLLNode<T> *prev = nullptr; // O(1)
    // buscar value en la lista
    // Complejidad del ciclo: O(n)
    while (p != nullptr && p->data != value) { // Se repite n veces en el peor de los casos  <----
      prev = p; // O(1)
      p = p->next; // O(1)
    }
    // si existe value en la lista
    if (p != nullptr) // O(1)
      p->data = newValue; // O(1)
    else
      throw std::out_of_range("No se encontró el valor en la lista"); // O(1)
  }  
}


// Complejidad: O(n)
template<class T>
void DoubleLinkedList<T>::updateAt(int position, T newValue){
  if (position < 0 || position >= numElements) { // O(1)
    throw std::out_of_range("Indice fuera de rango"); // O(1)
  }
  else {
    DLLNode<T> *p = head; // O(1)
    int index = 0; // O(1)
    // Complejidad del ciclo: O(n)
    while (p != nullptr) { // Se repite n veces  <----
      if (index == position) // O(1)
        p->data = newValue; // O(1)
      index++; // O(1)
      p = p->next; // O(1)
    }
  }
}


// Complejidad: O(n)
template<class T>
int DoubleLinkedList<T>::findData(T value){
  if (numElements > 0) { // O(1)
    DLLNode<T> *p = head; // O(1)
    DLLNode<T> *previo = nullptr; // O(1)
    int index = 0; // O(1)
    // buscar value en la lista
    // Complejidad del ciclo: O(n)
    while (p != nullptr && p->data != value) { // Se repite n veces en el peor de los casos  <----
      previo = p; // O(1)
      p = p->next; // O(1)
      index++; // O(1)
    }
    // si existe value en la lista
    if (p != nullptr) // O(1)
      return index; // O(1)
    else
      return -1; // O(1)
      throw std::out_of_range("No se encontró el valor en la lista"); // O(1)
  }  
  return -1; // O(1)
}


// Complejidad: O(n)
template<class T>
void DoubleLinkedList<T>::operator = (DoubleLinkedList<T> &other){
  DLLNode<T> *p = head, *prev = nullptr; // O(1)
    DLLNode<T> *ptrDLRecibida = other.head;
  // Vaciar los objetos que ya tenemos en nuestra lista
  ~DoubleLinkedList(); // O(n)

    // Complejidad del ciclo: O(n)
    while (ptrDLRecibida != nullptr) { // Se repite n veces
      addLast(ptrDLRecibida->data); // O(1)
      ptrDLRecibida = ptrDLRecibida->next; // O(1)
    }

}


// Complejidad: O(1)
//https://www.geeksforgeeks.org/quicksort-for-linked-list/
template <class T> 
void DoubleLinkedList<T>::swap( T* valueA, T* valueB ) 
{ 
  T temporal = *valueA; // O(1)
  *valueA = *valueB; // O(1)
  *valueB = temporal; // O(1)
} 

// Complejidad: O(n)
template<class T>
DLLNode<T>* DoubleLinkedList<T>::particion(DLLNode<T> *inicio, DLLNode<T> *fin){
  DLLNode<T> pivote = fin->data; // O(1)
  DLLNode<T> *i = inicio->prev; // O(1)
  // Complejidad del ciclo: O(n)
  for (DLLNode<T>  *j = inicio; j != fin; j = j->next){ // Se repite n veces
    if (j->data <= pivote.data){ // O(1)
      i = (i == nullptr)? inicio : i->next; // O(1)
      swap(&(i->data), &(j->data)); // O(1)
    } 
  } 
  i = (i == nullptr)? inicio : i->next; // O(1)
  swap(&(i->data), &(fin->data)); // O(1)
  return i; // O(1)
} 

// Complejidad: 2T(n/2) + T(1) = O(nlogn)
template<class T>
void DoubleLinkedList<T>::quickSort(DLLNode<T> *inicio, DLLNode<T> *fin){
  if (fin != nullptr && inicio != fin && inicio != fin->next)  { // O(1)
    DLLNode<T> *pivot = particion(inicio,fin); // O(n)
    quickSort(inicio, pivot->prev); //  <---- 1
    quickSort(pivot->next, fin); //  <---- 2
  }   
}//}

// Complejidad: O(nlogn)
template<class T>
void DoubleLinkedList<T>::sort(){
  quickSort(head,tail); // O(nlogn)
}


// Complejidad: O(n)
//https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/
template<class T>
void DoubleLinkedList<T>::invert(){
    DLLNode<T> *ptr = head; // O(1)
    DLLNode<T> *temporal; // O(1)
  // Complejidad del ciclo: O(n)
    while (ptr != nullptr){ // Se repite n veces  <----
        temporal = ptr->prev; // O(1)
        ptr->prev = ptr->next; // O(1)
        ptr->next = temporal; // O(1)  
        ptr = ptr->prev; // O(1)
    } 
    if(temporal != nullptr ) {    // Revisando si la lista está vacia o tiene sólo un nodo antes de actualizar
        head = temporal->prev; // O(1)
      }  
} // (geeksforgeeks,2022) 


// Complejidad: O(n)
template<class T>
DoubleLinkedList<T> DoubleLinkedList<T>::getReversedSublist(int inicio, int fin){
  DoubleLinkedList<T> nuevaLista; // O(1)
  DLLNode<T> *ptr = head; // O(1)
  int index = 0; // O(1)
  while (ptr != nullptr) { // Se repite n veces  <----
    if (index >=inicio && index <= fin){ // O(1)
      nuevaLista.addFirst(ptr->data); // O(1)
    }
    index++; // O(1)
    ptr = ptr->next; // O(1)
  }
  return nuevaLista; // O(1)
}

#endif // _DoubleLinkedList_H_