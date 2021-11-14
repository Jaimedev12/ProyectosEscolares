#include "Cliente.h"

Cliente::Cliente()
{
	this->nombre;
	this->telefono;
	this->direccion;
	this->horaRec;
}

Cliente::~Cliente(){}

void Cliente::guardarDatos(string nom, string tel, string dir, string horas)
{
	this->nombre = nom;
	this->telefono = tel;
	this->direccion = dir;
	this->horaRec = horas;
}

string Cliente::datos2String()
{
	string tempString;
	
	tempString = "Nombre del cliente: " + this->nombre + "\n";
	tempString = tempString + "Telefono del cliente: " + this->telefono + "\n";
	tempString = tempString + "Direccion del cliente: " + this->direccion + "\n";
	tempString = tempString + "Hora de recoleccion: " + this->horaRec + "\n";
	
	return tempString;
}
