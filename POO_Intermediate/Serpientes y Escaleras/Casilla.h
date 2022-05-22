#include <iostream>

using namespace std;

class Casilla{
  private:
    int numero;
    string tipo;
    //int cantidadMovimiento;

  public:
    Casilla();
    Casilla(int numero, string tipo);

    void setNumero(int numero);
    void setTipo(string tipo);
    //void setCantidadMovimiento(int cantidadMovimiento);

    int getNumero();
    string getTipo();
    //int getCantidadMovimiento();
};

Casilla::Casilla(){
  this->numero = 0;
  this->tipo = "";
  //this->cantidadMovimiento = 0;
}

Casilla::Casilla(int numero, string tipo){
  this->numero = numero;
  this->tipo = tipo;
  //this->cantidadMovimiento = cantidadMovimiento;
}

void Casilla::setNumero(int numero){
  this->numero = numero;
}

void Casilla::setTipo(string tipo){
  this->tipo = tipo;
}

/*
void Casilla::setCantidadMovimiento(int cantidadMovimiento){
  this->cantidadMovimiento = cantidadMovimiento;
}
*/

int Casilla::getNumero(){
  return numero;
}

string Casilla::getTipo(){
  return tipo;
}

/*
int Casilla::getCantidadMovimiento(){
  if (tipo == "N"){
    return 0;
  } else if (tipo == "S"){
    return -3;
  } else {
    return 3;
  }
  
}
*/
