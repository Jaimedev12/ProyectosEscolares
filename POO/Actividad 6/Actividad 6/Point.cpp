#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {
	this->coordx = 0;
	this->coordy = 0;
}

Point::Point(int x, int y) {
	this->coordx = x;
	this->coordy = y;
}

Point::~Point() {}

void Point::setCoords(int x, int y) {
	this->coordx = x;
	this->coordy = y;
}

int Point::getCoordX() {
	return coordx;
}

int Point::getCoordY() {
	return coordy;
}