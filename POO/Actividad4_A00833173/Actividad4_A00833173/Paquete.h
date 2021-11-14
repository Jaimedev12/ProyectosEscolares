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

	void guardarDatos(float p, float x, float y,float z);
	string datos2String();
	

};

