#pragma once
#include <iostream>
#include "Point.h"
using namespace std;


class Triangle
{
private:
	Point* vertex1;
	Point* vertex2;
	Point* vertex3;
	double perimetro;
	double superficie;
	double lado1;
	double lado2;
	double lado3;
	double semip;

public:
	Triangle();
	Triangle(Point* point1, Point* point2, Point* point3);
	~Triangle();

	double perimeter();
	double area();
	double getLado1();
	double getLado2();
	double getLado3();
	double getSemiP();
};



