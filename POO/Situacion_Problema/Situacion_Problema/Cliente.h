#pragma once
#include "Articulo.h"
#include "Tienda.h"
#include <string>
using namespace std;

class Cliente
{
private:
	string nombre;
	int numeroDeArticulosEnCarrito;
	int numeroMaximoArticulosEnElCarrito;
	Articulo** arregloArticulosEnCarrito;

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
	void agregarArticuloAlCarrito(Tienda* tienda, int indice);

};

