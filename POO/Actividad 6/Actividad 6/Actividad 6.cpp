// Actividad 6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Point.h"
#include "Triangle.h"
using namespace std;

int main()
{
	// COSAS IMPORTANTES
	// No explica cómo hacer la clase de puntos así que ahí me la inventé como yo pensé que sería


	// Esta es para crear el Triángulo con valores por omisión
	//Triangle* triangle = new Triangle();

	// Aquí se crea el triángulo con puntos personalizados
	Triangle* triangle = new Triangle(new Point(0, 0), new Point(10, 10), new Point(20, 0));

	cout << "Lado 1: " << triangle->getLado1() << endl;
	cout << "Lado 2: " << triangle->getLado2() << endl;
	cout << "Lado 3: " << triangle->getLado3() << endl;
	cout << "Semiperimetro: " << triangle->getSemiP() << endl;
	cout << "Perimetro: " << triangle->perimeter() << endl;
	cout << "Area: " << triangle->area() << endl;
}

