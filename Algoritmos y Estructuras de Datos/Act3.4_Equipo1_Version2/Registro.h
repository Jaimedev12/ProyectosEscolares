#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include "Ip.h"
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iostream>

class Registro {
  private:
    std::string mes;
    std::string dia;
    std::string hora;
    std::string min;
    std::string seg;
    std::string ip;
    std::string puerto;
    std::string msg;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;
    
    // usado para transformar fecha completa a segundos desde 1970
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    struct tm dateStruct;     // Struct que contiene todos los datos de la fecha-hora
    
  public:
    Ip ipObject;    // Representación numérica de la ip
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string ip, std::string puerto, std::string msg);
    std::string getAll();
    std::string getDate();
    void setDate(int fecha); 
    Ip getIpObject();
    // sobre carga de operadores de comparacion
    // Comapara dos objetos de la clase Registro usando
    // su valor numérico de ip
    bool operator ==(const Registro&) const;
    bool operator !=(const Registro&) const;
    bool operator >(const Registro&) const;
    bool operator <(const Registro&) const;
    bool operator >=(const Registro&) const;
    bool operator <=(const Registro&) const;
};

#endif //_REGISTRO_H_
