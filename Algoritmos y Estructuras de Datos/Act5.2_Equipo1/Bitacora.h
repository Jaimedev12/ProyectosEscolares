#ifndef _BITACORA_H_
#define _BITACORA_H_
/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
*/
#include "Ip.h"
#include "MaxHeap.h"
#include "Graph.h"
#include "HashTable.h"

using std::vector;

class Bitacora {
  private:
    Graph<Ip> graphRegistros;
    vector< std::pair<Ip, int>> listaIpGrado;
    MaxHeap<std::pair<int, std::string>> maxHeapIpGrado; 
    HashTable <uint, ResumenIp> hashIps; // <numericIP, ResumenIp> 
    void getIPSummary(string ipRecibido); 
     
  public:
    Bitacora();
    ~Bitacora();
    HashTable <uint, ResumenIp> inicializaHash();
    void printListAccesosIp(int ipRecibido);
    void sumaryIp();
};

#endif // _BITACORA_H_
