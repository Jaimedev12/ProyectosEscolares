// Actividad 6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Point.h"
#include "Triangle.h"
using namespace std;

int main()
{
	Triangle* triangle = new Triangle();

	cout << "Lado 1: " << triangle->getLado1() << endl;
	cout << "Lado 2: " << triangle->getLado2() << endl;
	cout << "Lado 3: " << triangle->getLado3() << endl;
	cout << "Semiperimetro: " << triangle->getSemiP() << endl;
	cout << "Perimetro: " << triangle->perimeter() << endl;
	cout << "Area: " << triangle->area() << endl;


}

