#pragma once
#include "Articulo.h"
#include <string>
using namespace std;

class Cliente
{
private:
	string nombre;
	int numeroDeArticulosEnCarrito;
	int articulosMaximosEnCarrito;
	Articulo** articulosEnCarrito;

public:
	Cliente();
	Cliente(string nombre);
	~Cliente();

	//---Setters-----------------------------------
	void setNombre(string nombre);

	//---Getters-----------------------------------
	string getNombre();
	Articulo** getArticulosEnCarrito();
	double getTotalAPagar();

	//---Funciones Especiales----------------------
	void agregarArticuloAlCarrito(Articulo* articulo);


};

