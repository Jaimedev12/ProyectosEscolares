#pragma once
class Destinatario
{
private:
	float peso;
	float largo, ancho, alto;

public:
	Destinatario();
	~Destinatario();

	void guardarDatos(int p, int x, int y, int z)
	{
		this->peso = p;
		this->largo = x;
		this->ancho = y;
		this->alto = z;
	}

};

