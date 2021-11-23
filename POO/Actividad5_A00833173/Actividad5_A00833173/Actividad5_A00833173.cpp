// Actividad 5 - A00833173
// Jaime Eduardo López Castro

#include <iostream>
#include "Alumno.h"
using namespace std;

int main()
{
    Alumno* alumno = new Alumno("A00833173", "Jaime Eduardo Lopez Castro", 18, "ITC");

    alumno->imprimirAlumno();

    cout << endl;
    alumno->cumpleanios();
    cout << alumno->getEdad() << endl;

    alumno->setEdad(21);
    alumno->setCarrera("IID");
    alumno->setMatricula("A01234567");
    alumno->setNombre("Juan Antonio Garza Sada");

    cout << endl;
    cout << alumno->getNombre() << endl;
    cout << alumno->getMatricula() << endl;
    cout << alumno->getCarrera() << endl;
    cout << alumno->getEdad() << endl;

}
