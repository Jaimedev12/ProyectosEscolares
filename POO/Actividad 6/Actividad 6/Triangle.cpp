#include "Triangle.h"
#include <iostream>
#include<cmath>
using namespace std;

Triangle::Triangle() {
	this->vertex1 = new Point(0, 0);
	this->vertex2 = new Point(50, 30);
	this->vertex3 = new Point(25, 10);

	// Es ta de aquí es la ecuación de Herón, solo tienes que saber que sí jala xdd
	this->lado1 = sqrt((pow((vertex1->getCoordX() - vertex2->getCoordX()), 2)) + (pow((vertex1->getCoordY() - vertex2->getCoordY()), 2)));
	this->lado2 = sqrt((pow((vertex2->getCoordX() - vertex3->getCoordX()), 2)) + (pow((vertex2->getCoordY() - vertex3->getCoordY()), 2)));
	this->lado3 = sqrt( (pow((vertex3->getCoordX() - vertex1->getCoordX()), 2)) + (pow((vertex3->getCoordY() - vertex1->getCoordY()), 2)));
	this->semip = (lado1 + lado2 + lado3) / 2;

}

Triangle::Triangle(Point* point1, Point* point2, Point* point3) {
	this->vertex1 = point1;
	this->vertex2 = point2;
	this->vertex3 = point3;
	this->lado1 = sqrt((pow((vertex1->getCoordX() - vertex2->getCoordX()), 2)) + (pow((vertex1->getCoordY() - vertex2->getCoordY()), 2)));
	this->lado2 = sqrt((pow((vertex2->getCoordX() - vertex3->getCoordX()), 2)) + (pow((vertex2->getCoordY() - vertex3->getCoordY()), 2)));
	this->lado3 = sqrt((pow((vertex3->getCoordX() - vertex1->getCoordX()), 2)) + (pow((vertex3->getCoordY() - vertex1->getCoordY()), 2)));
	this->semip = (lado1 + lado2 + lado3) / 2;


}

Triangle::~Triangle() {}

double Triangle::perimeter() {
	return lado1 + lado2 + lado3;
}

double Triangle::area() {
	return sqrt(semip * (semip - lado1) * (semip - lado2) * (semip - lado3));
}

double Triangle::getLado1() {
	return lado1;
}

double Triangle::getLado2() {
	return lado2;
}

double Triangle::getLado3() {
	return lado3;
}

double Triangle::getSemiP() {
	return semip;
}
