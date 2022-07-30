#include "Ip.h"
#include <vector>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;

//Complejidad: O(n)
Ip::Ip(){
  ipString = "";   //O(1) 
  numericIp = 0;   //O(1)
  indice = 0;      //O(1)
  accesos = 0; //O(1)  
  adyacencias = 0; //O(1)
  resumenIp.setResumenIp(ipString, accesos, adyacencias);
}

//Complejidad: O(n)
Ip::Ip(string ipString, int indice){
  this->ipString = ipString; //O(1)

  std::vector<int> p; //O(1)
  std::stringstream ss(ipString); //O(1)

  int temp;  //O(1)
  char chr; //O(1)
  
  while (ss >> temp){ //O(n)
    p.push_back(temp); //O(1)
    ss >> chr; //O(1)
  }

  temp = 0; //O(1)
  temp += 16777216 * p[0]; //O(1)
  temp += 65536 * p[1]; //O(1)
  temp += 256 * p[2]; //O(1)
  temp += p[3]; //O(1)

  numericIp = temp; //O(1)
  this -> indice = indice; //O(1)
  accesos = 0; //O(1)  
  adyacencias = 0; //O(1)
//  this -> repeticiones = repeticiones; //O(1)
  resumenIp.setResumenIp(ipString, accesos, adyacencias);
}

//Complejidad: O(n)
Ip::Ip(string ipString){
  this->ipString = ipString; //O(1)

  std::vector<int> p; //O(1)
  std::stringstream ss(ipString); //O(1)

  int temp;  //O(1)
  char chr; //O(1)
  
  while (ss >> temp){ //O(n)
    p.push_back(temp); //O(1)
    ss >> chr; //O(1)
  }
  resumenIp.setResumenIp(ipString, accesos, adyacencias);
}


//Complejidad: O(1)
 int Ip:: getIndice(){
  return indice; //O(1)
}

// Complejidad: O(1)
string Ip::getIpString(){
  return ipString; //O(1)
}

// Complejidad: O(1)
uint Ip::getNumericIp(){
  return numericIp; //O(1)
}

// Complejidad:  O(1)
void Ip::addAdyacencias(){
  adyacencias++; //O(1)
}

// Complejidad:  O(1)
void Ip::setAdyacencias(int repeticiones){
  this -> adyacencias = repeticiones; //O(1)
}

// Complejidad: O(1)
int Ip::getAdyacencias(){
  return adyacencias; //O(1)
}

// Complejidad:  O(1)
void Ip::addAccesos(){
  accesos++; //O(1)
}

// Complejidad:  O(1)
void Ip::setAccesos(int entradas){
  this -> accesos = entradas; //O(1)
}

// Complejidad: O(1)
int Ip::getAccesos(){
  return accesos; //O(1)
}

// Complejidad: O(1)
void Ip::printIp(){
//  std::cout << ipString << " " << repeticiones << std:: endl; //O(1)
  std::cout << ipString ;
}

// Complejidad: O(1)
bool Ip::operator==(const Ip &other) const {
  return this->numericIp == other.numericIp; //O(1)
}

// Complejidad: O(1)
bool Ip::operator!=(const Ip &other) const {
  return this->numericIp != other.numericIp; //O(1)
}

// Complejidad: O(1)
bool Ip::operator>(const Ip &other) const {
  return this->numericIp > other.numericIp; //O(1)
}

// Complejidad: O(1)
bool Ip::operator<(const Ip &other) const {
  return this->numericIp < other.numericIp; //O(1)
}

// Complejidad: O(1)
bool Ip::operator<=(const Ip &other) const {
  return this->numericIp <= other.numericIp; //O(1)
}

// Complejidad: O(1)
bool Ip::operator>=(const Ip &other) const {
  return this->numericIp >= other.numericIp; //O(1)
}

