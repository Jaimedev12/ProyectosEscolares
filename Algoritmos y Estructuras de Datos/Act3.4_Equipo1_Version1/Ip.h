#ifndef _IP_H_
#define _IP_H_

#include <string>
#include <iostream>

using std::string;

class Ip {

  private:
    string ipString;
    uint numericIp;
    int repeticiones;

  public:
    Ip();
    Ip(string ipString, int repeticiones);
    string getIpString();
    uint getNumericIp();
    void setRepeticiones(int repeticiones);
    int getRepeticiones();
    void printIp();

    bool operator ==(const Ip&) const;
    bool operator !=(const Ip&) const;
    bool operator >(const Ip&) const;
    bool operator <(const Ip&) const;
    bool operator >=(const Ip&) const;
    bool operator <=(const Ip&) const;

};

#endif // _IP_H_
