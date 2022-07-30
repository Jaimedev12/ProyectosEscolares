#include <iostream>

using namespace std;

int factorialIterativo(int n){
  int result = 1;
  while(n > 0){
    result *= n;
    n = n - 1;
  }
  return result;
}

int factorialRecursivo(int n){
  if (n == 0){
    return 1;
  }  else{
    return factorialRecursivo(n-1)*n; 
  }
}

int main() {
  cout << "Método recursivo: " << factorialRecursivo(8) << endl;
  cout << "Método iterativo: " << factorialIterativo(8) << endl;

}