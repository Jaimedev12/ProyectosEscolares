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

public:
	Triangle();
	Triangle(Point* point1, Point* point2, Point* point3);
	~Triangle();

	double perimeter();
	double area();
};



