#ifndef __HASH_NODE_H_
#define __HASH_NODE_H_

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template <class K, class T> class HashNode {

private:
  K key;
  T data;
  int status;                // 0 empty, 1 used, 2 deleted
  std::vector<int> overflow; // used to easily find collision elements

public:
  HashNode();
  ~HashNode();
  K getKey();
  T getData();
  int getStatus();
  void printKey();
  void setKey(K keyVal);
  void setData(T dataVal);
  void clearData();
  void addToOverflow(int hashIndex);
  int getOverflowSize();
  int getOverflowAt(int index);
  void removeFromOverflow(int value);
};

// Complejidad: O(1)
template <class K, class T> 
HashNode<K, T>::HashNode() {
  key = 0; // O(1)
  status = 0; // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
HashNode<K, T>::~HashNode() {
  overflow.clear(); // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
K HashNode<K, T>::getKey() {
  if (status != 1)
    throw "Invalid operation: Empty node"; // O(1)
  return key; // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
void HashNode<K, T>::printKey(){
  std::cout << key ; // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
T HashNode<K, T>::getData() { return data; }

// Complejidad: O(1)
template <class K, class T> 
int HashNode<K, T>::getStatus() { return status; }

// Complejidad: O(1)
template <class K, class T> 
void HashNode<K, T>::setKey(K keyVal) {
  key = keyVal; // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
void HashNode<K, T>::setData(T dataVal) {
  if (status == 1)
    throw "Node has been taken"; // O(1)
  data = dataVal; // O(1)
  status = 1; // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
void HashNode<K, T>::clearData() { status = 0; }

// Complejidad: O(n) (amortizada)
template <class K, class T> 
void HashNode<K, T>::addToOverflow(int hashIndex) {
  overflow.push_back(hashIndex); // O(n) (amortizada)
}

// Complejidad: O(1)
template <class K, class T> 
int HashNode<K, T>::getOverflowSize() {
  return overflow.size(); // O(1)
}

// Complejidad: O(1)
template <class K, class T> 
int HashNode<K, T>::getOverflowAt(int index) {
  return overflow[index]; // O(1)
}

// Complejidad: O(n)
template <class K, class T> 
void HashNode<K, T>::removeFromOverflow(int value) {
  std::vector<int>::iterator it =
      std::find(overflow.begin(), overflow.end(), value); // O(n)
  // If element was found remove it
  if (it != overflow.end()) {
    // remove element from overflow vector
    overflow.erase(overflow.begin() + (it - overflow.begin())); // O(n)
  }
}

#endif // __HASH_NODE_H_