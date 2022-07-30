#ifndef _IRESUMENP_H_
#define _RESUMENIP_H_

#include <string>
#include <iostream>

using std::string;

class ResumenIp {

  private:
    string direccionIp;
    int accesosHaciaIp;  // (número de aristas llegando a la IP)
    int adyacenciasDeIp; // (número de aristas saliendo de la IP)
  public:
    ResumenIp();
    ResumenIp(string direccionIp, int accesosHaciaIp, int adyacenciasDeIp);
    void setResumenIp(string direccionIp, int accesosHaciaIp, int adyacenciasDeIp);
    string getStringIp();
    void printResumen();
};

#endif //_IRESUMENP_H_
