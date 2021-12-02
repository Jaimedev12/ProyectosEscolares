#pragma once
#include "Articulo.h"
#include <string>
using namespace std;

class Tienda
{
private:
	string nombre;
	int numeroDeArticulosALaVenta;
	int articulosMaximosALaVenta;
	Articulo** arregloArticulosALaVenta;
public:
	Tienda();
	Tienda(string nombre);
	~Tienda();

	//---Setters-----------------------------------
	void setNombre(string nombre);

	//---Getters-----------------------------------
	string getNombre();
	Articulo** getArticulosALaVenta();

	//---Funciones Especiales----------------------
	void ponerArticuloALaVenta(Articulo* articulo);
};

