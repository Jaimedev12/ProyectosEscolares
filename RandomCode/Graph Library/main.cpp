#include "Graph.h"
using namespace std;

int main() {

  Graph grafo;

  grafo.addNode(0, {2, 1});
  grafo.addNode(1, {});
  grafo.addNode(2, {4});
  grafo.addNode(3, {5});
  grafo.addNode(4, {});
  grafo.addNode(5, {});

  grafo.addSingleEdge(1, 3);

  cout << endl;
  
  grafo.printGraph();

  grafo.BFT(0);
  cout << endl;
  grafo.DFT(0);
  
}
