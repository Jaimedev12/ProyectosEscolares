// Actividad 6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Point.h"
#include "Triangle.h"
using namespace std;

int main()
{
	Triangle* triangle = new Triangle();

	cout << triangle->getLado1() << endl;
	cout << triangle->getLado2() << endl;
	cout << triangle->getLado3() << endl;
	cout << triangle->getSemiP() << endl;



}

