#pragma once
#include <string>
using namespace std;

class Alumno
{
private:
	string matricula;
	string nombre;
	int edad;
	string carrera;

public:
	Alumno();
	Alumno(string matricula, string nombre, int edad, string carrera);

	string getMatricula();
	string getNombre();
	int getEdad();
	string getCarrera();

	void setMatricula(string matricula);
	void setNombre(string nombre);
	void setEdad(int edad);
	void setCarrera(string carrera);

	void imprimirAlumno();
	void cumpleanios();
};

