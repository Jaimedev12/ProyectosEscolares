#include "DistinctIp.h"


DistinctIp::DistinctIp() {
  
}

// Complejidad: O(1)
DistinctIp::DistinctIp(Ip ip){
  this->ip = ip; //O(1)
}

// Complejidad: O(1)
Ip DistinctIp::getIp() {
  return ip; //O(1)
}

// Complejidad: O(1)
bool DistinctIp::operator ==(DistinctIp &other) {
  return this->ip.getRepeticiones() == other.ip.getRepeticiones(); //O(1)
}

// Complejidad: O(1)
bool DistinctIp::operator !=(DistinctIp &other) {
  return this->ip.getRepeticiones() != other.ip.getRepeticiones(); //O(1)
}

// Complejidad: O(1)
bool DistinctIp::operator >(DistinctIp &other) {
  return this->ip.getRepeticiones() > other.ip.getRepeticiones(); //O(1)
}

// Complejidad: O(1)
bool DistinctIp::operator <(DistinctIp &other) {
  return this->ip.getRepeticiones() < other.ip.getRepeticiones();//O(1)
}

// Complejidad: O(1)
bool DistinctIp::operator >=(DistinctIp &other) {
  return this->ip.getRepeticiones() >= other.ip.getRepeticiones(); //O(1)
}

// Complejidad: O(1)
bool DistinctIp::operator <=(DistinctIp &other) {
  return this->ip.getRepeticiones() <= other.ip.getRepeticiones(); //O(1)
}