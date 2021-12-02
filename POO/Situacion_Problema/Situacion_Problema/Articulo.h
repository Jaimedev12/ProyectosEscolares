#pragma once
#include <string>
using namespace std;

class Articulo
{
private:
	double precio;
	string nombre;
public:
	Articulo();
	Articulo(string nombre, double precio);
	~Articulo();

	// ---Setters------------------------------------
	void setPrecio(double precio);
	void setNombre(string nombre);

	//---Getters-------------------------------------
	double getPrecio();
	string getNombre();
};

