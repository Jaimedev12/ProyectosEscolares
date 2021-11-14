#include "Paquete.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Paquete::Paquete() 
{
	this->peso = 0;
	this->largo = 0;
	this->ancho = 0;
	this->alto = 0;
}

Paquete::~Paquete(){}

void Paquete::guardarDatos(float p, float x, float y, float z)
{
	this->peso = p;
	this->largo = x;
	this->ancho = y;
	this->alto = z;
}

string Paquete::datos2String()
{
	string tempString;
	string tempLargo = to_string(this->largo);
	string tempAncho = to_string(this->ancho);
	string tempAlto = to_string(this->alto);

	tempString = "Peso del paquete (kg): " + to_string(this->peso) + "\n";
	tempString = tempString + "Dimensiones del paquete (cm): " + tempLargo + " x " + tempAncho + " x " + tempAlto + "\n";

	return tempString;
}