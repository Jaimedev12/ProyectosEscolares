#include "Destinatario.h"
using namespace std;

Destinatario::Destinatario()
{
	this->nombreDestinatario;
	this->telefonoDestinatario;
	this->direccionDestinatario;
}

Destinatario::~Destinatario() {}

void Destinatario::guardarDatos(string nombre, string telefono, string direccion)
{
	this->nombreDestinatario = nombre;
	this->telefonoDestinatario = telefono;
	this->direccionDestinatario = direccion;
}

string Destinatario::datos2String()
{
	string tempString;

	tempString = "Nombre del destinatario: " + this->nombreDestinatario + "\n";
	tempString = tempString + "Telefono del destinatario: " + this->telefonoDestinatario + "\n";
	tempString = tempString + "Direccion del destinatario: " + this->direccionDestinatario + "\n";

	return tempString;
}
