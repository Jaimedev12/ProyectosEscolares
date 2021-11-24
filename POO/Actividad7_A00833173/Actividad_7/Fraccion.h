#pragma once
class Fraccion
{
private:
	int num;
	int den;

public:
	Fraccion();
	Fraccion(int num, int den);
	~Fraccion();

	void setNum(int num);
	void setDen(int den);

	int getNum();
	int getDen();

	double calcValorReal(); 
	void imprimeFraccion();
};

