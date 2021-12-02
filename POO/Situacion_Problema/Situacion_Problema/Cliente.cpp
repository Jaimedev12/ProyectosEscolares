#include "Cliente.h"

//---Constructores y destructores ---------------
Cliente::Cliente()
{
	this->nombre = "";
	this->arregloArticulosEnCarrito = 0;
	this->numeroMaximoArticulosEnElCarrito = 10;
	this->arregloArticulosEnCarrito = new Articulo * [this->numeroMaximoArticulosEnElCarrito];
}

Cliente::Cliente(string nombre)
{
	this->nombre = nombre;
	this->arregloArticulosEnCarrito = 0;
	this->numeroMaximoArticulosEnElCarrito = 10;
	this->arregloArticulosEnCarrito = new Articulo * [this->numeroMaximoArticulosEnElCarrito];
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
	return arregloArticulosEnCarrito;
}

double Cliente::getTotalAPagar()
{
	double total = 0;
	for (int i = 0; i < this->numeroDeArticulosEnCarrito; i++)
	{
		total += arregloArticulosEnCarrito[i]->getPrecio();
	}
	return total;
}

//---Funciones Especiales----------------------
void Cliente::agregarArticuloAlCarrito(Tienda* tienda, int indice)
{
	//Este if lo que hace es ver si el arreglo ya se llen�
	// si ya se llen� lo hace m�s grande y luego copia todo lo que hab�a en el arreglo anterior a ese
	if (this->numeroDeArticulosEnCarrito == this->numeroMaximoArticulosEnElCarrito)
	{
		this->numeroMaximoArticulosEnElCarrito += 10;
		Articulo** arregloTemporal = new Articulo * [this->numeroMaximoArticulosEnElCarrito];
		for (int i = 0; i < this->numeroDeArticulosEnCarrito; i++)
		{
			arregloTemporal[i] = arregloArticulosEnCarrito[i];
		}
		delete[] arregloArticulosEnCarrito;
		this->arregloArticulosEnCarrito = arregloTemporal;
	}
	//�sta l�nea agrega el art�culo del �ndice que pusimos como par�metro al carrito del cliente y luego
	// aumenta el n�mero de art�culos en el carrito por uno
	this->arregloArticulosEnCarrito[this->numeroDeArticulosEnCarrito] = tienda->getArticulosALaVenta()[indice];
	this->arregloArticulosEnCarrito++;

}
