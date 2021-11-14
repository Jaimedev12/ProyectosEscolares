#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
	string nombre, telefono, direccion, horaRec;

public:

	Cliente();
	~Cliente();

	void guardarDatos(string nombre, string tel, string dir, string horas);
	string datos2String();
};

