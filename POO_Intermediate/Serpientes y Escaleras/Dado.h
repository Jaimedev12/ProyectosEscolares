#include <random>
#include <time.h>

class Dado{
  private:
    int nLados;
    int ladoArriba;
  public:
    Dado();
    Dado(int lados);

    void setLadoArriba(int lado);
    void setNLados(int nLados);

    int getLadoArriba();

    void lanzar();
};

Dado::Dado(){
  this->nLados = 6;
  this->ladoArriba = 1;
}

Dado::Dado(int lados){
  this->nLados = lados;
  this->ladoArriba = 1;
}

void Dado::setLadoArriba(int lado){
  this->ladoArriba = lado;
}

void Dado::setNLados(int nLados){
  this->nLados = nLados;
}

int Dado::getLadoArriba(){
  return this->ladoArriba;
}

void Dado::lanzar(){
  srand(time(0));
  int temp = rand() % nLados + 1;
  ladoArriba = temp;
}