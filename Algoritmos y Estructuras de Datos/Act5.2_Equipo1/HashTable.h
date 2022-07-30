#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "HashNode.h"

template<class K, class T>
class HashTable {
  private:
    std::vector<HashNode<K,T>> table;
    int numElements;
    int maxCapacity; // preferible un numero primo
    int colisiones;

  public:
    HashTable();
    HashTable(int selectedMaxSize);
    ~HashTable();
    int getHashIndex(K keyVal);
    void setCapacity(int newMaxSize);
    int getSize();
    int getTotalColisiones();
    void print();
    void add(K keyVal, T value);
    int find(K keyVal);
    T getDataAt(int index);
    void remove(K keyVal);
};

//Complejidad: O(1)
template<class K, class T>
HashTable<K, T>::HashTable() {
  maxCapacity = 0; //O(1)
  numElements = 0; //O(1)
  colisiones = 0; //O(1)
  table = std::vector<HashNode<K,T>>(maxCapacity); //O(1)
}

// Complejidad: O(1)
template<class K, class T>
HashTable<K, T>::~HashTable() {
  table.clear(); // O(1)
}

//Complejidad: O(1)
template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize) {
  maxCapacity = selectedMaxSize; //O(1)
  numElements = 0; //O(1)
  colisiones = 0; //O(1)
  table = std::vector<HashNode<K,T>>(maxCapacity); //O(1)
}

// Hash function recibe una llave
// Complejidad: O(1)
template<class K, class T>
int HashTable<K, T>::getHashIndex(K keyVal) {
  return keyVal % maxCapacity; //O(1)
}

// Complejidad: O(1)
template<class K, class T>
void HashTable<K, T>::setCapacity(int newMaxSize) {
  maxCapacity = newMaxSize; // O(1)
}

// Complejidad: O(1)
template<class K, class T>
int HashTable<K, T>::getSize() {
  return numElements; // O(1)
}

//Complejidad: O(n)
template<class K, class T>
void HashTable<K,T>::print() {
  std::cout << "Content of the hash table: " << std::endl;
    std::cout << std::endl;
  
  for (int i = 0; i < maxCapacity; i++) { // O(n)
    // status:  0 empty, 1 used, 2 deleted
    
    if (table[i].getStatus() == 1){// Cell is used
      std::cout << "Cell: " << i << ", Key: " << table[i].getKey() << ", Value: \n" ; //O(1)
      table[i].getData().printResumen() ;  //O(1)
      std::cout<< "Overflow.size: " << table[i].getOverflowSize() << std::endl; //O(1) 
      std::cout << std::endl; //O(1)
      } 
  }
}

// Complejidad: O(n)
// Esta complejidad es solamente en el peor de todos los casos, ya que 
// usualmente se encontrará un lugar vacío mucho antes
template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) {
  if (numElements == maxCapacity) { //O(1)
    throw std::out_of_range("Hash Table is full"); // O(1)
  }
  
  // Compute the index of the table using a key and a hash function
  int hashVal = getHashIndex(keyVal); // O(1)
  HashNode<K, T> node = table[hashVal]; // O(1)
  
  // status:  0 empty, 1 used, 2 deleted
  if (node.getStatus() != 1) { // Cell is free
    node.setKey(keyVal); // O(1)
    node.setData(value); // O(1)
    table[hashVal] = node; // O(1)
  }
  else { // Cell is already taken
    // Find next free space using quadratic probing
    // https://www.geeksforgeeks.org/quadratic-probing-in-hashing/
    int i = 1; // O(1)
    int currentHashVal = getHashIndex(hashVal + i * i); // O(1)
    HashNode<K, T> currentNode = table[currentHashVal]; // O(1)

    // Peor de los casos es O(n), aunque casi siempre va a ser mucho menos
    while (currentNode.getStatus() == 1) { // Cell is used
      i++;
      currentHashVal = getHashIndex(hashVal + i * i); // O(1)
      currentNode = table[currentHashVal]; // O(1)
      colisiones++; //cada vez que al añadir un valor se encuentre con una celda ocupada, se suma uno a colisiones
    }
    // A free cell was found
    currentNode.setKey(keyVal);  // O(1)
    currentNode.setData(value); // O(1)
    node.addToOverflow(currentHashVal); // O(n)
    table[currentHashVal] = currentNode; // O(1)
    table[hashVal] = node; // O(1)
  }
/*      std::cout << std::endl<< "Key regresado de add ";
      node.printKey();   usado para comprobacion
      std::cout << std::endl;*/
  numElements++;
}  

//Complejidad: O(n)
template<class K, class T>
int HashTable<K,T>::find(K keyVal) {
  int hashVal = getHashIndex(keyVal); // O(1)
  HashNode<K, T> node = table[hashVal];//O(1)
  
  // status:  0 empty, 1 used, 2 deleted
  if (node.getStatus() == 1) { // Cell is used
    if (node.getKey() == keyVal) {
      return hashVal;
    }
    for (int i = 0; i < node.getOverflowSize(); i++) { //O(n)
      int overflowIndex = node.getOverflowAt(i);   //O(1)
      
      if (table[overflowIndex].getKey() == keyVal) {
        return overflowIndex; //O(1)
      }
    }
    return -1;
  }
  return -1;
}

//Complejidad: O(1)
template<class K, class T>
T HashTable<K,T>::getDataAt(int index) {
  return table[index].getData(); //O(1)
}

//Complejidad: O(1)
template<class K, class T>
void HashTable<K,T>::remove(K keyVal) {
  int pos, hashVal; // O(1)
  pos = find(keyVal);
  if (pos == -1) {
    throw std::invalid_argument("Element does not exist in hash table"); // O(1)
  }
  hashVal = getHashIndex(keyVal); // O(1)
  if (pos != hashVal) {
    HashNode<K, T> node = table[hashVal]; //O(1)
    node.removeFromOverflow(pos); //O(1)
    table[hashVal] = node; //O(1)
  }
  table[pos].clearData(); //O(1)
}

//Complejidad: O(1)
template<class K, class T>
int HashTable<K,T>::getTotalColisiones(){
  return colisiones;//O(1)
}

#endif // __HASH_TABLE_H_

