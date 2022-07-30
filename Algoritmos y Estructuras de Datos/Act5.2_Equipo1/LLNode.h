#ifndef _NODE_H_
#define _NODE_H_

  template <class T>
  class LLNode { 
  public: 
      T data; 
      LLNode<T> *next;
      LLNode();
      LLNode(T val);        
  }; 

//Complejidad: O(1)
  template<class T>
  LLNode<T>::LLNode() : data{}, next{nullptr} {} // O(1)

//Complejidad: O(1)
  template<class T>
  LLNode<T>::LLNode(T val){
      data = val; // O(1)
      next = nullptr; // O(1)
  }

#endif // _NODE_H_