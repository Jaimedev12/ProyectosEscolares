#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "LLNode.h"

template <class T>
class LinkedList {
    private:
      LLNode<T>* head;
      LLNode<T>* tail;
      int numElements;

    public:
      LinkedList();
      ~LinkedList();
      int getNumElements();
      void printList();
      void addFirst(T value);
      void addLast(T value);
      T getData(int position);
      LLNode<T>* getHead();

};


//Complejidad: O(1)
template<class T>
LinkedList<T>::LinkedList() {
  //std::cout << "--->Creando una lista vacia" << std::endl;
  head = nullptr; //O(1)
  tail = nullptr; //O(1)
  numElements = 0; //O(1)
}


//Complejidad: O(n)
template<class T>
LinkedList<T>::~LinkedList() {
  //std::cout << "--->Liberando memoria de la lista ligada" << std::endl;
  LLNode<T> *p, *q;
  p = head;
  while (p != nullptr) { //Se repite hasta n veces = O(n)
    q = p->next;//O(1)
    delete p;//O(1)
    p = q;//O(1)
  }
  head = nullptr;//O(1)
  tail = nullptr;//O(1)
  numElements = 0;//O(1)
}


//Complejidad: O(1)
template<class T>
int LinkedList<T>::getNumElements() {
  return numElements;//O(1)
}


//Complejidad: O(n)
template<class T>
void LinkedList<T>::printList() {
  LLNode<T> *ptr = head;//O(1)
  while (ptr != nullptr) {//Se repite hasta n veces = //O(n)
      std::cout << ptr->data << " ";//O(1)
      ptr = ptr->next;//O(1)
  }
  std::cout << std::endl;//O(1)
}


//Complejidad: O(1)
template<class T>
void LinkedList<T>::addFirst(T value) {
  LLNode<T> *newLLNode = new LLNode<T>(value);//O(1)
  newLLNode->next = head; //O(1)
  head = newLLNode;//O(1)
  if (numElements == 0) //O(1)
    tail = newLLNode;//O(1)
  numElements++;    //O(1)
}


//Complejidad: O(1)
template<class T>
void LinkedList<T>::addLast(T value) {
  if (head == nullptr) {
    addFirst(value);//O(1)
  }
  else {
    LLNode<T> *newLLNode = new LLNode<T>(value);//O(1)
    newLLNode->next = nullptr;//O(1)
    tail->next = newLLNode;//O(1)
    tail = newLLNode;//O(1)
    numElements++;//O(1)
  }
}


//Complejidad:  O(n)
template<class T>
T LinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");//O(1)
  }
  else {
    if (position == 0)
      return head->data;//O(1)
    LLNode<T> *p = head;//O(1)
    int index = 0;//O(1)
    while (p != nullptr) {//Se repite hasta n veces
      if (index == position)
        return p->data;//O(1)
      index++;//O(1)
      p = p->next;//O(1)
    }
    return {};//O(1)
  }
}


//Complejidad: O(1)
template<class T>
LLNode<T> * LinkedList<T>::getHead() {
  return head;//O(1)
}

#endif // _LINKEDLIST_H_