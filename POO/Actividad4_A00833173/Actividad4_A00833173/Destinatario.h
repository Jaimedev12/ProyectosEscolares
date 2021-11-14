#pragma once
#include <iostream>
#include <string>
using namespace std;

class Destinatario
{
	//el sistem también registrará el destino(nombre de destinatario, teléfono, dirección)
private:
	string nombreDestinatario, telefonoDestinatario, direccionDestinatario;

public:
	Destinatario();
	~Destinatario();

	void guardarDatos(string nombre, string telefono, string direccion);
	string datos2String();


};

