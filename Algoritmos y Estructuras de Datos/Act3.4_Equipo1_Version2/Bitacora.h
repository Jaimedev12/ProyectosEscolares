#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Registro.h"
#include "MaxHeap.h"

using std::vector;

class Bitacora {
  private:
    // vector de objetos Ip
    vector<Registro> listaDatos;
    MaxHeap<Ip> listaIps;
    void heapify (vector<Registro> &vector, int heapSize, int index);
    void heapSort(vector<Registro> &vector, int heapSize);

  public:
    Bitacora();
    ~Bitacora();
    void lecturaDatos(std::string fileName);
    void printVector();
    void printHeap();
    void printInDateRange(int beg, int end);
    void topFive(); 


    // ordenamiento y búsqueda
    void sortByDate();
    int  findByDate(int key);
    void heapSort();
    void sortByIp();

    void exportToTxt(std::string fileString);
    void exportTxt(std::string fileString);
    void HeapExportTxt(std::string fileString);

    void contabilizarIP();
    MaxHeap<Ip> getListaIps(); 

};

#endif // _BITACORA_H_
