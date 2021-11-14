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
	int horas;
	int minutos;

public:
	Cliente();
	~Cliente();
};

