#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Registro.h"
#include "DistinctIp.h"
#include "MaxHeap.h"

using std::vector;

class Bitacora {
  private:
    vector<Registro> listaRegistros;

    MaxHeap<std::pair<int, Ip>> heapEjemplo;

    vector<DistinctIp> listaIps;
    MaxHeap<Registro> heapRegistros;
    MaxHeap<DistinctIp> heapIps;

  public:
    Bitacora();
    ~Bitacora();
    void lecturaDatos(std::string fileName);

    void sortRegistrosByIp();
    void sortDistinctIpsByRepeticiones();

    void ordenarIpsByRepeticiones(std::string fileName);

    void exportRegistrosToTxt(std::string fileString);
    void exportIpsToTxt(std::string fileString);
    void exportIpsConMayorAcceso(int n, std::string fileString);
    void printIpsConMayorAcceso(int n);

    void contabilizarIP();
    vector<Registro> getListaRegistro();

};

#endif // _BITACORA_H_
