// Situacion_Problema.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Articulo.h"
#include "Cliente.h"
#include "Tienda.h"
#include <iostream>

using namespace std;

int main()
{
	Cliente* cliente = new Cliente("Jaime");
	Tienda* tienda1 = new Tienda("Abarrotes El Chapo");
	Articulo* articulo1 = new Articulo("Chela", 15.0f);

	tienda1->ponerArticuloALaVenta(articulo1);
	cliente->agregarArticuloAlCarrito(tienda1, 0);

	cout << tienda1->getArticulosALaVenta()[0]->getNombre();
	cout << cliente->getArticulosEnCarrito()[0]->getNombre();

	//Articulo** articulosEnElCarrito = cliente->getArticulosEnCarrito();
	//cout << articulosEnElCarrito[0]->getNombre();
	//cout << cliente->getTotalAPagar();
}