#include "Articulo.h"
#include "Cliente.h"


//---Constructores y destructores ---------------
Articulo::Articulo() 
{
	this->nombre = "";
	this->precio = 0;
}

Articulo::Articulo(string nombre, double precio)
{
	this->nombre = nombre;
	this->precio = precio;
}

Articulo::~Articulo()
{
	delete this;
}


// ---Setters------------------------------------
void Articulo::setPrecio(double precio) 
{
	this->precio = precio;
}

void Articulo::setNombre(string nombre)
{
	this->nombre = nombre;
}

//---Getters-------------------------------------
double Articulo::getPrecio()
{
	return precio;
}

string Articulo::getNombre()
{
	return this->nombre;
}

