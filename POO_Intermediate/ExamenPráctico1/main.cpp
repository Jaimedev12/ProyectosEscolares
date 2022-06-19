#include <iostream>
#include <vector>

using namespace std;

/*

Lo que pasa es que yo hice la pregunta uno directamente con apuntadores
en vez de crear un muestraDatos() diferente para cada clase.

Así que yo hice la pregunta 2 en vez de la 1

*/

// -------- CLASE PERSONA ------------------
class Persona {
protected:
    string nombre;
    int edad;
    string nacionalidad;

public:
    Persona();
    Persona(string, int, string);

    virtual void muestraDatos();
};

Persona::Persona(){
    nombre = "";
    edad = 0;
    nacionalidad = "";
}

Persona::Persona(string nombre, int edad, string nacionalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->nacionalidad = nacionalidad;
}

void Persona::muestraDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
}
//-----------------------------------------

// ---------- CLASE MEDICO --------------------
class Medico : public Persona{
private:
    string especialidad;

public:
    Medico();
    Medico(string, int, string, string);

    void muestraDatos();
};

Medico::Medico() : Persona(){
    especialidad = "";
}

Medico::Medico(string nombre, int edad, string nacionalidad, string especialidad):
Persona(nombre, edad, nacionalidad){
    this->especialidad = especialidad;
}

void Medico::muestraDatos(){
    Persona::muestraDatos();
    cout << "Especialidad: " << especialidad << endl;
}
// --------------------------------------------

// ---------- CLASE PACIENTE --------------------
class Paciente : public Persona{
private:
    string diagnostico;
public:
    Paciente();
    Paciente(string, int, string, string);

    void muestraDatos();
};

Paciente::Paciente() : Persona(){
    diagnostico = "";
}

Paciente::Paciente(string nombre, int edad, string nacionalidad, string diagnostico):
Persona(nombre, edad, nacionalidad){
    this->diagnostico = diagnostico;
}

void Paciente::muestraDatos(){
    Persona::muestraDatos();
    cout << "Diagnóstico: " << diagnostico << endl;
}

// ----------------------------------------------


int main(){

    vector<Persona*> personas(10);

    personas[0] = new Medico("Jaime", 18, "Mexicana", "Endocrinólogía");
    personas[1] = new Medico("Juan", 19, "Holandesa", "En gripa");
    personas[2] = new Medico("María", 20, "Alemana", "Ginecología");
    personas[3] = new Medico("Flor", 21, "Venezolana", "Pediatría");
    personas[4] = new Medico("Frida", 22, "Puerto Riqueña", "General");
    personas[5] = new Paciente("Cristina", 23, "Canadiense", "Le duele la panza");
    personas[6] = new Paciente("Angélica", 24, "Turca", "Gripa");
    personas[7] = new Paciente("Enrique", 25, "Peruana", "Dolor de cabeza");
    personas[8] = new Paciente("Josefino", 26, "Arábica", "Durmió mal");
    personas[9] = new Paciente("Alfonso", 27, "Japonesa", "Mal humor");
    
    for (int i = 0; i < personas.size(); i++){
        personas[i]->muestraDatos();
        cout << endl;
    }

    return 0;
}