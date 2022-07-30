#ifndef _GRAPH_H_
#define _GRAPH_H_

/*#include <iostream>
#include <sstream>

#include <vector>*/
#include <string>
#include <fstream>
#include <utility> 
#include <map>
#include <set>
#include <queue>
#include <cstring> 
#include <string.h>
#include "LinkedList.h"
#include "Ip.h"
#include "MaxHeap.h"
//#include "QueueLinkedList.h"

#define INF 0x3f3f3f3f

template <class T>
class Graph {
  private:
    int numNodes; //cantidad de direcciones de ip 
    int numEdges; //cantidad incidencias
    // Cada nodo tiene un id y un objeto de datos tipo T
    std::map<unsigned int, Ip> nodesInfo;
    // Lista de adyacencia, vector de listas ligadas de pares (vertice, peso)
    std::vector<LinkedList<std::pair<int, int>>> adjList; //<int indice, int peso>

    std::vector<Ip> vectorIps;
    void split(std::string line, std::vector<int> &res);

  public:
    Graph();
    ~Graph();
    void readGraph(std::string fileName);
    int  getNumNodes();
    std::pair<unsigned int, ResumenIp> getPairsInfo(int indice);
    void print();
    void printGraphInfo();
    std::vector<T> levelData(int find);
    int getDataIndex(string data);
    MaxHeap<std::pair<int, std::string>> heapAdyacencias();
    MaxHeap<std::pair<int, std::string>> heapDistancias;
    uint getKeyV(int indice);
};

//Complejidad: O(1)
template <class T>
Graph<T>::Graph() {
  numNodes = 0; // O(1)
  numEdges = 0; // O(1)
}

//Complejidad: O(1)
template <class T>
Graph<T>::~Graph() {
  adjList.clear();
  numNodes = 0; // O(1)
  numEdges = 0; // O(1)
}

//Complejidad: O(1)
// El tiempo varía ligeramente dependiendo de la longitud de la línea
// Pero a fines prácticos es constante
template <class T>
void Graph<T>::split(std::string line, std::vector<int> &res) {
  size_t strPos = line.find(" "); // O(1) -- Longitud de la línea
  size_t lastPos = 0; // O(1)
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos))); // O(1)
    lastPos = strPos + 1; // O(1)
    strPos = line.find(" ", lastPos); // O(1) -- Longitud de la línea
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos))); // O(1)
}

//Complejidad: O(n^2)
// En realidad la complejidad sería el número de líneas multiplicado por el
// número de nodos
//  Codigo original de: Rodríguez, E.(2022) Asesoria-Act4-3-SofiaGerardo-25Jul2022.mp4 Recuperado de: https://drive.google.com/drive/folders/1x7ujNORKfqr1KJwHNbeTuUSth49eWG40
template <class T>
void Graph<T>::readGraph(std::string fileName) {
  std::string line, ip1, ip2, peso; // O(1)
  int i = 0; // O(1)
  std::ifstream file(fileName); // O(1)
  if (!file.good()) {
    file.close(); // O(1)
    throw std::invalid_argument("File not found"); // O(1)
  }
  else {
    // Complejidad del ciclo: O(n * (n + 2*nlogn)) = O(n^2)
    while(std::getline(file,line)) { // Se repite n veces (número de líneas)

      // Complejidad del if: O(n) -- número de nodos
      if (i == 0) {
        std::vector<int> res; // O(1)
        split(line, res); // O(1)
        numNodes = res[0]; // O(1)
        numEdges = res[1]; // O(1)
        // Reservar memoria para los renglones de la lista de adyacencia 
        adjList.resize(numNodes+1); // O(1)
        vectorIps.resize(numNodes+1); // O(1)
        
        // Declara una lista vacia para cada renglon y la almacena en el vector
        for (int k = 1; k <= numNodes; k++) { // Se repite n veces
          LinkedList<std::pair<int,int>> tmpList; // en ponderado lista de pares
          adjList[k] = tmpList; // O(1)
        }
      }

      // Complejidad del else if: O(logn)
      else if (i > 0 && i <= numNodes) {
        Ip tmpIP(line, i); // O(1)
        vectorIps[i] = tmpIP; // O(1)
        nodesInfo.insert({tmpIP.getNumericIp(), tmpIP}); // {numericIP, Ip} // O(logn)
      } 

      // Complejidad del else if: O(logn)
      else if (i > numNodes) {
        // La complejidad de los .find() en el string varían de acuerdo a su
        // longitud, por lo que podemos decir que es constante
        std::size_t found = line.find(":", 15); // O(1)
        ip1 = line.substr(15, found-15); // O(1)
        std::size_t found2 = line.find(" ", found+1); // O(1)
        std::size_t found3 = line.find(":", found2+1); // O(1)
        ip2 = line.substr(found2, found3-found2); // O(1)
        std::size_t found4 = line.find(" ", found3+1); // O(1)
        std::size_t found5 = line.find(" ", found4+1); // O(1)
        peso = line.substr(found4, found5-found4); // O(1)
        // Crear arista ip1 a ip2 con un peso
        Ip tmpIP1(ip1, 0); // O(1)
        Ip tmpIP2(ip2, 0); // O(1)
        std::map<unsigned int, Ip>::iterator it1, it2; // O(1)
        int ip1Index, ip2Index; // O(1)
        it1 = nodesInfo.find(tmpIP1.getNumericIp()); // O(logn)  
        if(it1 != nodesInfo.end())
          ip1Index = it1->second.getIndice(); // O(1)
        it2 = nodesInfo.find(tmpIP2.getNumericIp()); // O(logn)
        if(it2 != nodesInfo.end())
          ip2Index = it2->second.getIndice(); // O(1)
        adjList[ip1Index].addLast({ip2Index, stoi(peso)}); // O(1)
        it1->second.addAdyacencias();
        it2->second.addAccesos();
    // tmpIP1 se conecta con tmpIP2 por lo que a tmpIP1 se le aumenta en uno su atributo adyacencias
        vectorIps[ip1Index].addAdyacencias(); // O(1) 
   // lo que quiere decir que tmpIP2 es accedido por tmpIP1, por lo que a tmpIP2 se le aumenta en uno su atributo accesos
        vectorIps[ip2Index].addAccesos(); // O(1) 
    
      }
      i++; // O(1)
    }
    file.close(); // O(1)
  }
}

// Complejidad: O(1)
template <class T>
int  Graph<T>::getNumNodes(){
  return numNodes; // O(1)
}

// Complejidad: O(n^2)
// Número de nodos por el número de adyacencias
template <class T>
void Graph<T>::print(){
	  std::cout << "Adjacency List" << std::endl; // O(1)
		for (int u = 1; u <= numNodes; u++){ // Se repite n veces
      std::cout << "vertex " << u << " (" ; // O(1)
      vectorIps[u].printIp(); // O(1)
      std::cout  << "): "; // O(1)
      // Se repite de acerdo al número de adjacencias
      for (int j = 0; j < adjList[u].getNumElements(); j++) { 
        std::pair<int, int> p = adjList[u].getData(j); // O(1)
        
        std::cout << "{" << p.first << ", " << p.second 
          << "} "; // O(1)
      }
      std::cout <<  vectorIps[u].getAdyacencias() << std::endl; // O(1)
    } 
}

//Complejidad: O(nlogn)
template <class T>
MaxHeap<std::pair<int, std::string>> Graph<T>::heapAdyacencias() {
  MaxHeap<std::pair<int, std::string>> tmpMaxHeap; // O(1)
  std::cout << std::endl; // O(1)
  for (int i = 1; i <= numNodes; i++) { // Se repite n veces
    // O(logn)
   tmpMaxHeap.push(std::make_pair(vectorIps[i].getAdyacencias(), vectorIps[i].getIpString()));
  }
  return tmpMaxHeap;  // O(1)
}

//Complejidad: O(logn) - Buscar en un map
template <class T> 
int Graph<T>::getDataIndex(string data){  //sigue la logica de getBootMasterIndex() usado en act 4.3
  Ip tmData(data,0);
 std::map<unsigned int, Ip>::iterator itData; // O(1)
  int dataIndex; // O(1)
  itData = nodesInfo.find(tmData.getNumericIp()); // O(1).getNumericIp()); // O(logn) 
  if(itData != nodesInfo.end()){
    dataIndex = itData->second.getIndice(); // O(1)
      return dataIndex; // O(1)
    }
  return -1; // O(1)
}

// Complejidad: O(1)
template <class T>
uint Graph<T>::getKeyV(int indice){
  uint keyVal = vectorIps[indice].getNumericIp(); // O(1)
  return keyVal;   // <numericIP, ResumenIp>  keyVal, value // O(1)
}

// Complejidad: O(1) 
template <class T>
std::pair< uint , ResumenIp> Graph<T>::getPairsInfo(int indice){
  
  uint keyVal = vectorIps[indice].getNumericIp(); // O(1)

vectorIps[indice].resumenIp.setResumenIp(vectorIps[indice].getIpString(),vectorIps[indice].getAccesos(),vectorIps[indice].getAdyacencias());
  
  ResumenIp value = vectorIps[indice].resumenIp; // O(1)
  
  return std::make_pair(keyVal, value);   // <numericIP, ResumenIp>  keyVal, value // O(1)
}

// Complejidad: O(n) en el peor peor de los casos, pero  como no todos los 
// están conectados entre sí, en la práctica es mucho menor.
template <class T>
std::vector<T> Graph<T>::levelData(int find){
  std::vector<T> nivel; // O(1)
//  int findIndex = getDataIndex();
// Recorremos los vertices vecinos del valor recibido
  LLNode<std::pair<int, int>>  *ptr = adjList[find].getHead();
  while (ptr != nullptr) { //Se repite hasta n veces = //O(n)
    std::pair<int,int> par = ptr->data; // O(1) (indice, peso)
    int vecinoIndex = par.first; // O(1)    
    T tmp = vectorIps[vecinoIndex]; // O(1)
    nivel.push_back(tmp); // O(n) - Número de enlaces    
    ptr = ptr->next;//O(1)
  }
  return nivel;
}



#endif  // _GRAPH_H_
