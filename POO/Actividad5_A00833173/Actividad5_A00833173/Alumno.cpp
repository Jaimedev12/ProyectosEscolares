#include "Alumno.h"
#include <iostream>
#include <string>
using namespace std;

Alumno::Alumno() {
	this->matricula = "";
	this->nombre = "";
	this->edad = 0;
	this->carrera = "";
}

Alumno::Alumno(string matricula, string nombre, int edad, string carrera) {
	this->matricula = matricula;
	this->nombre = nombre;
	this->edad = edad;
	this->carrera = carrera;
}

//--------------------------------------------------------------------------------

string Alumno::getMatricula() {
	return matricula;
}

string Alumno::getNombre() {
	return nombre;
}

int Alumno::getEdad() {
	return edad;
}

string Alumno::getCarrera() {
	return carrera;
}

void Alumno::setMatricula(string matricula) {
	this->matricula = matricula;
}

void Alumno::setNombre(string nombre) {
	this->nombre = nombre;
}

void Alumno::setEdad(int edad) {
	this->edad = edad;
}

void Alumno::setCarrera(string carrera) {
	this->carrera = carrera;
}

//-----------------------------------------------------

void Alumno::imprimirAlumno() {
	cout << "Matricula: " << matricula << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
	cout << "Carrera: " << carrera << endl;
}

void Alumno::cumpleanios() {
	this->edad = this->edad + 1;
}

