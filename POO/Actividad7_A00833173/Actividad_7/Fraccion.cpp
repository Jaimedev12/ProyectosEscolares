#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion() {
	this->num = 1;
	this->den = 2;
}

Fraccion::Fraccion(int num, int den) {
	this->num = num;
	this->den = den;
}

Fraccion::~Fraccion() {}

//----------------------------------------------------------------------------------------------------

void Fraccion::setNum(int num) {
	this->num = num;
}

void Fraccion::setDen(int den) {
	this->den = den;
}

int Fraccion::getNum() {
	return num;
}

int Fraccion::getDen() {
	return den;
}

//---------------------------------------------------------------------------------------------

double Fraccion::calcValorReal() {
	double valorReal = 0;

	valorReal = static_cast<double>(this->num) / (this->den);
	return valorReal;
}

void Fraccion::imprimeFraccion() {
	cout << this->getNum() << "/" << this->getDen() << " Valor real: " << this->calcValorReal() << endl;
}



