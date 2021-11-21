#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle() {
	this->vertex1 = new Point(0, 0);
	this->vertex2 = new Point(50, 30);
	this->vertex3 = new Point(25, 10);
}

Triangle::Triangle(Point point1, Point point2, Point point3) {
	this->vertex1 = point1;
	this->vertex2 = point2;
	this->vertex3 = point3;
}

Triangle::~Triangle() {}

double Triangle::perimeter() {

}

double Triangle::area() {

}
