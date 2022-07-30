#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Registro.h"

using std::vector;

class Bitacora {
  private:
    // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
    std::vector<Registro> listaRegistros;

  public:
    Bitacora();
    ~Bitacora();
    void lecturaDatos(std::string fileName);
    void print();
    void printInDateRange(int beg, int end);

    // ordenamiento y búsqueda
    void sortByDate();
    int findByDate(int key);

    vector<Registro> getListaRegistros();
    

};

#endif // _BITACORA_H_

