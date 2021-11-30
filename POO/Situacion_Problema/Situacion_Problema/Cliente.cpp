#include "Cliente.h"

//---Constructores y destructores ---------------
Cliente::Cliente()
{
	this->nombre = "";
	this->articulosEnCarrito = 0;
	this->articulosMaximosEnCarrito = 10;
}

Cliente::Cliente(string nombre)
{
	this->nombre = nombre;
	this->articulosEnCarrito = 0;
	this->articulosMaximosEnCarrito = 10;
}

Cliente::~Cliente()
{
	delete this;
}

//---Setters-----------------------------------
void Cliente::setNombre(string nombre)
{
	this->nombre = nombre;
}

//---Getters-----------------------------------
string Cliente::getNombre()
{
	return nombre;
}

Articulo** Cliente::getArticulosEnCarrito()
{
	return articulosEnCarrito;
}

double Cliente::getTotalAPagar()
{
	double total = 0;
	for (int i = 0; i < this->numeroDeArticulosEnCarrito; i++)
	{
		total += articulosEnCarrito[i]->getPrecio();
	}
	return total;
}

//---Funciones Especiales----------------------
void Cliente::agregarArticuloAlCarrito(Articulo* articulo)
{
	if (this->numeroDeArticulosEnCarrito == this->articulosMaximosEnCarrito)
	{
		this->numeroDeArticulosEnCarrito = this->articulosMaximosEnCarrito + 10;
		Articulo** temp = new Articulo* [this->articulosMaximosEnCarrito];
		for (int i = 0; i < this->numeroDeArticulosEnCarrito; i++)
		{
			temp[i] = this->articulosEnCarrito[i];
		}
		delete[] this->articulosEnCarrito;
		this->articulosEnCarrito = temp;
	}

	this->articulosEnCarrito[this->numeroDeArticulosEnCarrito] = articulo;
	this->articulosEnCarrito++;
}
