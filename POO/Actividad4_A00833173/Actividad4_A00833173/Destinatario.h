#pragma once
#include <iostream>
#include <string>
using namespace std;

class Destinatario
{
	//el sistem tambi�n registrar� el destino(nombre de destinatario, tel�fono, direcci�n)
private:
	string nombreDestinatario, telefonoDestinatario, direccionDestinatario;

public:
	Destinatario();
	~Destinatario();

	void guardarDatos(string nombre, string telefono, string direccion);
	string datos2String();


};

