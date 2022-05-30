#include "Graph.h"
using namespace std;

int main() {

  Graph grafo;

  grafo.addNode(0, {1, 2});
  grafo.addNode(1, {3});
  grafo.addNode(2, {4});
  grafo.addNode(3, {5});
  grafo.addNode(4, {});
  grafo.addNode(5, {});

  cout << endl;
  
  grafo.printGraph();

  grafo.BFT(0);
  
}





