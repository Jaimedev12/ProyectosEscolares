#pragma once
#include <iostream>
#include <string>
using namespace std;


class Paquete
{
private:
	float peso;
	float largo, ancho, alto;

public:
	Paquete();
	~Paquete();

	void guardarDatos(int p, int x, int y, int z);
	string datos2String();
	

};

