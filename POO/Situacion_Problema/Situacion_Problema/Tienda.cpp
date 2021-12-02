#include "Tienda.h"
#include <string>
using namespace std;

//---Constructores y destructores -----------------------------------------------------
Tienda::Tienda()
{
	this->nombre = "";
	this->numeroDeArticulosALaVenta = 0;
	this->articulosMaximosALaVenta = 10;
	this->arregloArticulosALaVenta = new Articulo * [this->articulosMaximosALaVenta];
}

Tienda::Tienda(string nombre)
{
	this->nombre = nombre;
	this->numeroDeArticulosALaVenta = 0;
	this->articulosMaximosALaVenta = 10;
	this->arregloArticulosALaVenta = new Articulo * [this->articulosMaximosALaVenta];
}

Tienda::~Tienda()
{

}

//---Setters-------------------------------------------------------------------
void Tienda::setNombre(string nombre)
{
	this->nombre = nombre;
}

//---Getters-------------------------------------------------------------------------
string Tienda::getNombre()
{
	return nombre;
}

Articulo** Tienda::getArticulosALaVenta()
{
	return arregloArticulosALaVenta;
}

//---Funciones Especiales--------------------------------------------------------
void Tienda::ponerArticuloALaVenta(Articulo* articulo)
{
	if (this->numeroDeArticulosALaVenta == this->articulosMaximosALaVenta)
	{
		this->articulosMaximosALaVenta = this->articulosMaximosALaVenta + 10;
		Articulo** nuevoArreglo = new Articulo * [this->articulosMaximosALaVenta];
		for (int i = 0; i < this->numeroDeArticulosALaVenta; i++)
		{
			nuevoArreglo[i] = this->arregloArticulosALaVenta[i];
		}
		delete[] this->arregloArticulosALaVenta;
		this->arregloArticulosALaVenta = nuevoArreglo;
	}

	this->arregloArticulosALaVenta[this->numeroDeArticulosALaVenta] = articulo;
	this->numeroDeArticulosALaVenta++;
}
