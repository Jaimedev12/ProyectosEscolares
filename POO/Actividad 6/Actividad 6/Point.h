#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int coordx;
	int coordy;

public:
	Point();
	Point(int x, int y);
	~Point();

	void setCoords(int x, int y);
};

