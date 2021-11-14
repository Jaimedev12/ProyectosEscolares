#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
	string nombre;
	int telefono;
	string direccion;
	int horasRec;
	int minutosRec;

public:
	Cliente();
	~Cliente();
};

