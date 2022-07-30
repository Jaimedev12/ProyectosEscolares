#include "Registro.h"

// Complejidad: O(n)
Registro::Registro() {
  mes = "";    // O(1)
  dia = "";    // O(1)
  hora = "";   // O(1)
  min = "";    // O(1)
  seg = "";    // O(1)
  ip = "";     // O(1)
  puerto = ""; // O(1)
  msg = "";    // O(1)
}

// Complejidad: O(n)
Registro::Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string ip, std::string puerto, std::string msg) {
  this->mes = mes;       // O(1)
  this->dia = dia;       // O(1)
  this->hora = hora;     // O(1)
  this->min = min;       // O(1)
  this->seg = seg;       // O(1)
  this->ip = ip;         // O(1)
  this->puerto = puerto; // O(1)
  this->msg = msg;       // O(1)
  ipObject = Ip(ip, 0);  // O(1)  

  // ---------------------  CALCULA LA FECHA EN SEGUNDOS --------------------------
  // tranforma fecha completa a segundos desde 1970
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = std::stoi(seg);   // O(1)
  dateStruct.tm_min = std::stoi(min);   // O(1)
  dateStruct.tm_hour = std::stoi(hora); // O(1)
  dateStruct.tm_mday = std::stoi(dia);  // O(1)
  
  // Agregado para resolver problema de compatibilidad en Windows
  dateStruct.tm_isdst = 0; // O(1)
  
  for (size_t i=0; i < meses.size(); i++) { // O(1)
   
    if (meses[i] == mes)
    
      dateStruct.tm_mon = i; // O(1)
  }
  
  dateStruct.tm_year = 2022 - 1900;  // Asumimos el año 2022
  
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct); // O(1)
  // -------------------------------------------------------------------------------

}

// Complejidad: O(1)
std::string Registro::getAll() {
  return mes + " " + dia + " " + hora + ":" + min + ":" + seg + " " + ip + ":" + puerto + " " + msg; // O(1)
}


// Complejidad: O(1)
std::string Registro::getDate(){
  return std::to_string(date);  // O(1)
}


// Complejidad: O(1)
void Registro::setDate(int fecha){
  date = fecha;  // O(1)
}


// Complejidad: O(1)
Ip Registro::getIpObject(){
  return ipObject;  // O(1)
}


// Complejidad:  O(1)
bool Registro::operator==(const Registro &other) const {
  //return this->date == other.date;
  return this->ipObject == other.ipObject;  //O(1)
}

// Complejidad:  O(1)
bool Registro::operator!=(const Registro &other) const {
  //return this->date != other.date;
  return this->ipObject != other.ipObject;  //O(1)
}

// Complejidad:  O(1)
bool Registro::operator>(const Registro &other) const {
  //return this->date > other.date;
  return this->ipObject > other.ipObject;  //O(1)
}

// Complejidad:  O(1)
bool Registro::operator<(const Registro &other) const {
  //return this->date < other.date;
  return this->ipObject < other.ipObject;  //O(1)
}

// Complejidad:  O(1)
bool Registro::operator<=(const Registro &other) const {
  //return this->date <= other.date;
  return this->ipObject <= other.ipObject; //O(1)
}

// Complejidad: O(1)
bool Registro::operator>=(const Registro &other) const {
  //return this->date >= other.date;
  return this->ipObject >= other.ipObject; //O(1)
}