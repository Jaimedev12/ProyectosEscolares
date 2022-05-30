#include <stack>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

/*

            TODO 

1.  Hacer que BFT y DFT 
funcionen en grafos cíclicos
2.  Implementar hasPath function
3.  Crear la opción para que
una unión sea unidireccional 
4.  Función para contar la cantidad 
de componentes del grafo (partes 
desconectadas)
5.  Función para contar la 
longitud 

  */
  

class Graph{
  int numVertices;
  map<int, vector<int>> adjList;
  map<int, vector<int>>::iterator mapIt;
  unordered_set<int> visited;
    
public:
  Graph();
  Graph(int V);
  void addNode(int value, vector<int> connections);
  void addSingleEdge(int src, int dest);
  void addDoubleEdge(int src, int dest);

  void printGraph();

  void DFT(int N);
  void BFT(int N);

  void dbgPrintGraph();
};

Graph::Graph(){
  vector<int> temp = {};
  
  for (int i = 0; i < 0; i++){
    addNode(i, temp);
  }
}

Graph::Graph(int V){

  numVertices = V;

  vector<int> temp = {};
  
  for (int i = 0; i < V; i++){
    addNode(i, temp);
  }
}

void Graph::addNode(int value, vector<int> connections){

  if (adjList.find(value) != adjList.end()){
    cout << "The number " << value << " is already in the graph" << endl;
    return;
  }
  
  adjList.insert(pair<int, vector<int>> (value, connections));
}

void Graph::addSingleEdge(int src, int dest){
  if ( (adjList.find(src) != adjList.end()) && (adjList.find(dest) != adjList.end()) ){
    
    mapIt = adjList.find(src);
    auto connections = mapIt->second;
    
    if ( find(connections.begin(), connections.end(), dest) == connections.end() )
      mapIt->second.push_back(dest); 
    
  } else {
    cout << "One of the 2 nodes is not in the Graph, please add it first" << endl;
  }
}

void Graph::addDoubleEdge(int src, int dest){
   if ( (adjList.find(src) != adjList.end()) && (adjList.find(dest) != adjList.end()) ){
    
    mapIt = adjList.find(src);
    auto connections = mapIt->second;
    if ( find(connections.begin(), connections.end(), dest) == connections.end() )
      mapIt->second.push_back(dest); 
     
    mapIt = adjList.find(dest);
    connections = mapIt->second;
    if ( find(connections.begin(), connections.end(), src) == connections.end() )
      mapIt->second.push_back(src); 

  } else {
    cout << "One of the 2 nodes is not in the Graph, please add it first" << endl;
  }
}

void Graph::printGraph(){

  for (mapIt = adjList.begin(); mapIt != adjList.end(); mapIt++){

    cout  << mapIt->first << ": [";

    if(!mapIt->second.empty()){
      for (int i = 0; i < mapIt->second.size()-1; i++){
        cout << mapIt->second[i] << ", ";
      }
  
      cout << mapIt->second[mapIt->second.size()-1] << "]" << endl;
    } else{
      cout << "]" << endl;
    }
  }
}

void Graph::DFT(int N){

  visited.clear();
  stack<int> stack;
  stack.push(N);

  while(!stack.empty()){
    
    int current = stack.top();

    //vector<string> temp = {"a", "b", "c", "d", "e", "f"};
    //cout << temp[current] << endl;
    cout << current;
  
    mapIt = adjList.find(current);
    int nLinks = mapIt->second.size();
  
    stack.pop();
    visited.insert(current);
  
    for (int i = 0; i < nLinks; i++){
      stack.push(mapIt->second[i]);       
    }
  } 
}

void Graph::BFT(int N){
  visited.clear();
  queue<int> queue;
  queue.push(N);

  while(!queue.empty()){
    
    int current = queue.front();

    cout << current;
  
    mapIt = adjList.find(current);
    int nLinks = mapIt->second.size();
  
    queue.pop();
    visited.insert(current);
  
    for (int i = 0; i < nLinks; i++){

      queue.push(mapIt->second[i]); 
      
    }
  }
}


