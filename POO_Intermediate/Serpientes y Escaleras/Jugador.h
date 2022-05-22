
#include <iostream>

using namespace std;

class Jugador {
private:
  string nombre;
  int posicion;

public:
  Jugador(); // constructor default
  Jugador(string, int); //constructor con parametros

  // Set
  void setNombre(string);
  void setPosicion(int);

  // Get
  string getNombre();
  int getPosicion();
};

Jugador::Jugador(){
  this->nombre = "";
  this->posicion = 0;
}

Jugador::Jugador(string nombre, int posicion){
  this->nombre = nombre;
  this->posicion = posicion;
}

// constructor nombre Jugador
void Jugador::setNombre(string _nombre) {
  nombre = _nombre;
}

void Jugador::setPosicion(int _posicion) {
  posicion = _posicion;
}

string Jugador::getNombre() { return nombre; }
int Jugador::getPosicion() { return posicion; }