#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

template<class T>
class ListTemplate{
    private:
        vector<T> data;
        int currentSize;

    public:
        ListTemplate();

        bool insert(T value);
        void erase();
        T getData(int index);
        int getSize();
        void print();
};

template<class T>
ListTemplate<T>::ListTemplate(){
    currentSize = 0;
}

template<class T>
bool ListTemplate<T>::insert(T value){
    if (currentSize < MAX){
        data.push_back(value);
        currentSize++;
        return true;
    } else{
        return false;
    }
}

template<class T>
void ListTemplate<T>::erase(){
    if (currentSize > 0){
        cout << "Elemento borrado: " << getData(currentSize-1) << endl;
        data.pop_back();
        currentSize--;
    } else{
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template<class T>
T ListTemplate<T>::getData(int index){
    if (index >= 0 && index < currentSize){
        return data[index];
    } else{
        cout << "ÍNDICE NO EXISTENTE" << endl;
    }
}

template<class T>
int ListTemplate<T>::getSize(){
    return currentSize;
}

template<class T>
void ListTemplate<T>::print(){
    for (int i = 0; i < currentSize; i++){
        printf("[%d] - ", i);
        cout << data[i] << endl;
    }
}






#endif