#include "ResumenIp.h"

//Complejidad: O(1)
ResumenIp::ResumenIp(){
  direccionIp = ""; //O(1)
  accesosHaciaIp = 0;  //O(1)
  adyacenciasDeIp = 0; //O(1)
}

//Complejidad: O(1)
void ResumenIp::setResumenIp(string direccionIp, int accesosHaciaIp, int adyacenciasDeIp){
  this -> direccionIp = direccionIp; //O(1)
  this -> accesosHaciaIp = accesosHaciaIp; //O(1)
  this -> adyacenciasDeIp = adyacenciasDeIp; //O(1)
}

// Complejidad: O(1)
ResumenIp::ResumenIp(string direccionIp, int accesosHaciaIp, int adyacenciasDeIp){
  this -> direccionIp = direccionIp; //O(1)
  this ->  accesosHaciaIp = accesosHaciaIp; //O(1)
  this ->  adyacenciasDeIp = adyacenciasDeIp; //O(1)
}

// Complejidad: O(1)
string ResumenIp::getStringIp(){
  return direccionIp; //O(1)
}

// Complejidad: O(1)
void ResumenIp::printResumen(){
  std::cout << "Dirección IP: " << direccionIp << std::endl; //O(1)
  std::cout << "Numero de aristas llegando a la IP: " << accesosHaciaIp << std::endl; //O(1)
  std::cout << "Numero de aristas saliendo de la IP: " << adyacenciasDeIp << std::endl; //O(1)
}