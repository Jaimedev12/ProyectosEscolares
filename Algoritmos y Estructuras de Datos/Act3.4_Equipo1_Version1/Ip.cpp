#include "Ip.h"
#include <vector>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;

//Complejidad: O(n)
Ip::Ip(){
  ipString = ""; //O(1) 
  numericIp = 0; //O(1)
  repeticiones = 0; //O(1)
}

//Complejidad: O(n)
Ip::Ip(string ipString, int repeticiones){
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
  
  this -> repeticiones = repeticiones; //O(1)
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
void Ip::setRepeticiones(int repeticiones){
  this -> repeticiones = repeticiones; //O(1)
}

// Complejidad: O(1)
int Ip::getRepeticiones(){
  return repeticiones; //O(1)
}

// Complejidad: O(1)
void Ip::printIp(){
  std::cout << ipString << " " << repeticiones << std:: endl; //O(1)
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

