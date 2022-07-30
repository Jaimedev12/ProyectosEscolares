/*
  Autores:
    Luis Barajas 
    María Fernanda Vela Calderón  -  A01377958
    Jaime Eduardo López Castro - A00833173
    

  Fecha: 28/06/2022

  compilar: 
    g++ -std=c++17 -Wall *.cpp

  ejecutar:
    ./a.out
*/

#include <iostream>
using namespace std;

// Complejidad O(n)
int sumaRecursiva(int n){
  if(n == 1){
    return 1; // O(1)
  }
  return n + sumaRecursiva(n-1); // O(n)
}

// Complejidad O(1)
unsigned int sumConst(unsigned int n){
  uint res = (n*(n+1))/2; // O(1)
  return res; // O(1)
}

// Complejidad O(1 * n) = O(n)
uint sumIt(uint n){
  uint accum = 0; // O(1)

  for(int i = 0; i<= n; i++){ // Se repite n veces
    accum = accum + i; // O(1)
  }
  return accum; // O(1)
}

// Complejidad O(2^n)
int fibonacciRecursivo(int n){
  if( n <= 1){
    return n; // O(1)
  }else {
    int fib = fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2); // O(2^n)
  }
}

// Complejidad O(1*n) = O(n)
void fibonacciIterativo(int n){
  int a = 0, b = 1, i, fib=1; // O(1)
  if(n > 0){
    for(i = 1; i <= n; i++){ // Se repite n veces
      cout  << fib << ", "; // O(1)
      fib = a + b; // O(1)
      a = b; // O(1)
      b = fib; // O(1)
    }
  }
  else{cout << "El numero debe ser un entero positivo." << endl;} // O(1)
  cout << endl; // O(1)
}


int main() {
  
//sumConst
  cout << "sumConst(20): " << sumConst(20) << endl;
  cout << "sumConst(50): " << sumConst(50) << endl;
  cout << "sumConst(100): " << sumConst(100) << endl;
  cout << "sumConst(1000): " << sumConst(1000) << endl;
  cout << endl;
  
//sumaRecursiva
  cout<< "sumaRecursiva(20): " << sumaRecursiva(20)<< endl;
  cout<< "sumaRecursiva(50): " <<sumaRecursiva(50)<< endl;
  cout<< "sumaRecursiva(100): " <<sumaRecursiva(100)<< endl;
  cout<< "sumaRecursiva(1000): " <<sumaRecursiva(1000)<< endl;
  cout << endl;
  
//sumaIterativa  
  cout<<"sumaIterativa(20): "<<sumIt(20)<< endl;
  cout<<"sumaIterativa(50): "<<sumIt(50)<< endl;
  cout<<"sumaIterativa(100): "<<sumIt(100)<< endl;
  cout<<"sumaIterativa(1000): "<<sumIt(1000)<< endl;
  cout << endl;

//fibonacciRecursivo
// La complejidad de esta implementación es horrible
  // O(n*(2^n))
  cout<<"fibonacciRecursivo(5): ";
  for (int i = 0; i <= 5; i++){ // Se repite n veces
    cout << fibonacciRecursivo(i) << ", "; // O(2^n)
  }

  cout << endl;

  // O(n*(2^n))
  cout<<"fibonacciRecursivo(10): ";
  for (int i = 0; i <= 10; i++){ // Se repite n veces
    cout << fibonacciRecursivo(i) << ", "; // O(2^n)
  }

  cout << endl;

  // O(n*(2^n))
  cout<<"fibonacciRecursivo(15): ";
  for (int i = 0; i <= 15; i++){ // Se repite n veces
    cout << fibonacciRecursivo(i) << ", "; // O(2^n)
  }
  // Hasta aquí porque si no, tarda demasiado
  cout << endl << endl;

//fibonacciIterativo
  cout<<"fibonacciIterativo(5): "; fibonacciIterativo(5);
  cout<<"fibonacciIterativo(10): "; fibonacciIterativo(10);
  cout<<"fibonacciIterativo(15): "; fibonacciIterativo(15);
  cout<<"fibonacciIterativo(30): "; fibonacciIterativo(30);
  cout << endl;
}

