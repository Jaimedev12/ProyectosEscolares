#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "DoubleLinkedList.h"
#include "Registro.h"


using std::vector;

class Bitacora {
  private:
    // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
    DoubleLinkedList<Registro> listaRegistros;

  public:
    Bitacora();
    void lecturaDatos(std::string fileName);
    void print();
    void exportTxt(std::string fileString);
    //void exportToTxt(std::string file);
    void printInDateRange(DLLNode<Registro>* beg, DLLNode<Registro>* end); 
    void exportInRange(DLLNode<Registro>* beg, DLLNode<Registro>* end, std::string fileString);

    // ordenamiento y búsqueda
    void sortByDate();
    DLLNode<Registro>* findByDate(Registro key);

    DoubleLinkedList<Registro> getListaRegistros();
    
    

};

#endif // _BITACORA_H_

