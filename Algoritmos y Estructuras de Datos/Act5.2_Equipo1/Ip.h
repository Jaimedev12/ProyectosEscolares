#ifndef _IP_H_
#define _IP_H_

#include <string>
#include <iostream>
#include "ResumenIp.h"

using std::string;

class Ip {

  private:
    string ipString;
    uint numericIp;
    int indice;
    //int repeticiones;
    int accesos;     // (número de aristas llegando a la IP)
    int adyacencias; // (número de aristas saliendo de la IP)


  public:
    ResumenIp resumenIp;
    Ip();
    Ip(string ipString);
    Ip(string ipString, int indice);
//    Ip(string ipString, int repeticiones);
    string getIpString();
    uint getNumericIp();
    void setAdyacencias(int repeticiones);
    void addAdyacencias();
    int getAdyacencias();
    void setAccesos(int entradas);
    void addAccesos();
    int getAccesos();
    void printIp();
    int getIndice();

    bool operator ==(const Ip&) const;
    bool operator !=(const Ip&) const;
    bool operator >(const Ip&) const;
    bool operator <(const Ip&) const;
    bool operator >=(const Ip&) const;
    bool operator <=(const Ip&) const;

};

#endif // _IP_H_
