#include "Bitacora.h"

//Complejidad: O(n^2)
// En realidad la complejidad es el número de líneas por el número de nodos
Bitacora::Bitacora() {
  graphRegistros.readGraph("bitacoraGrafos.txt"); // O(n^2)
  hashIps =  inicializaHash(); // O(n)
  sumaryIp(); // manda llamar a getIPSummary(string ipRecibido) // O(nlogn)
}

Bitacora::~Bitacora() {}

// Complejidad: O(n)
HashTable <uint, ResumenIp> Bitacora::inicializaHash(){
//  int hashMaxCapacity = 53527; // prueba para disminuir colisiones
// hashMaxCapacity = (graphRegistros.getNumNodes() *  2) -> numero primo siguiente obtenido de https://es.numberempire.com/primenumbers.php
  int hashMaxCapacity = 26759; //26759 // O(1)
  HashTable<uint, ResumenIp> tmpHashIps(hashMaxCapacity); // O(1)
  int i=1; // O(1)
  while ( i <= graphRegistros.getNumNodes()){ // Se repite n veces
    std::pair< uint, ResumenIp> par = graphRegistros.getPairsInfo(i); // O(1)
    uint keyVal = par.first; //numericIp // O(1)
    ResumenIp value = par.second ; //ResumenIp // O(1)  
    
    try {
      tmpHashIps.add(keyVal, value); // (numericIP, ResumenIp) // O(n)
    }
    catch (std::out_of_range e) {
      std::cout << std::endl << "Ocurrio un error: " << e.what() << std::endl << "No se logro añadir resumen de IP, la tabla Hash se encuentra llena." << std::endl; // O(1)
    }
    i++; // O(1)
  }
  std::cout << "\nAl insertar "<< graphRegistros.getNumNodes() <<" resumenes de IPs \nen una tabla hash de tamaño " << hashMaxCapacity << ", \nel total de colisiones generadas es de " <<  tmpHashIps.getTotalColisiones()  << " . \n"<< std::endl; // O(1)
  return tmpHashIps; // O(1)
}


// metodo que imprima lista completa de direcciones accesadas desde la IP recibida, ordenadas en forma descendente
// Complejidad: O(2*nlogn) = O(nlogn)
// n representa la cantidad de enlaces
void Bitacora::printListAccesosIp(int ipRecibido){
//  ipRecibido.resumenIp.printResumen();
  MaxHeap<Ip> heapAccesosIp; //MaxHeap para guardar los accesos de la ip numericIp, // O(1)
  vector<Ip> ipsAccedidas = graphRegistros.levelData(ipRecibido); // O(1)
  for (int i = 0; i < ipsAccedidas.size(); i++){ // Se repite hasta n veces
    heapAccesosIp.push(ipsAccedidas[i]); // O(logn)
  }
  if (ipsAccedidas.size() == 0){
    std::cout << "\nLa direccion Ip reibida no ha accedido a ninguna direccion Ip. \n";    
  }
  else {
    std::cout << "\nLa direccion Ip reibida accedio a las siguientes direcciones Ip: \n";
    for (int i = 1; i <= ipsAccedidas.size(); i++){ // Se repite hasta n veces
      std::cout << "    " << heapAccesosIp.top().getIpString() << std::endl; // O(1)
      heapAccesosIp.pop(); // O(logn)
    }
  }
  std::cout <<std::endl;
}

// Complejidad: O(nlogn) en promedio
// n representa el número de enlaces
void Bitacora::getIPSummary(string ipRecibido){
  
  Ip tmpR(ipRecibido); // O(1)
  int in = graphRegistros.getDataIndex(ipRecibido); // O(1)
  uint keyBuscado = graphRegistros.getKeyV(in); // O(1)
  int buscadoIndex = hashIps.find(keyBuscado); // O(1) en promedio
  if (buscadoIndex == -1){
    std::cout << "\nLa direccion IP ingresada no se encuentra en la bitacora. \n" 
      << std::endl; // O(1)
  }
  else {
    std::cout <<std::endl; // O(1)
    ResumenIp infoIp = hashIps.getDataAt(buscadoIndex); // O(1)
    infoIp.printResumen(); // O(1)
    printListAccesosIp(in); // O(nlogn) en el peor de los casos
  }
}

// Complejidad: O(nlogn)
void Bitacora::sumaryIp(){
  std::cout << "Ingrese la direccion IP que desea buscar \n(En formato ###.##.###.### ): " ;
  std::string ipRecibido; // O(1)
  std::cin >> ipRecibido; // O(1)
  getIPSummary(ipRecibido); // O(nlogn)
}
