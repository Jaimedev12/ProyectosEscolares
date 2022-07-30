#ifndef _DISTINCT_IP_H_
#define _DISTINCT_IP_H_

// Esta clase existe pura y únicamente para hacer la sobrecarga de
// operadores en base al número de repeticiones de cada ip

#include "Ip.h"
#include <iostream>

class DistinctIp {

  private:
    Ip ip;

  public:
    DistinctIp();
    DistinctIp(Ip ip);

    Ip getIp();

    bool operator ==(DistinctIp&);
    bool operator !=(DistinctIp&);
    bool operator >(DistinctIp&);
    bool operator <(DistinctIp&);
    bool operator >=(DistinctIp&);
    bool operator <=(DistinctIp&);

};

#endif // _DISTINCT_IP_H_
