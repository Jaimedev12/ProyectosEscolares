//#ifdef Campus_h
#define Campus_h

#include "Program.h"

class Campus{
private:
    int capacity;
    string location;
    vector<Program> programs;
    int students;
    string name;

public:
    Campus();
    Campus(string name);
    Campus(string name, string location);

    void setCapacity(string capacity);
    void setLocation(string location);

    int getCapacity(int capacity);
    string getLocation(string location);

    void addStudents(int students);
    void addProgram(string program);
    void printPrograms();
    void print();
};

// Constructor por default
Campus::Campus()
{
    name = "";
    capacity = 0;
    location = "";
    students = 0;
}

Campus::Campus(string name)
{
    this->name = name;
    capacity = 0;
    location = "";
    students = 0;
}

Campus::Campus(string name, string location)
{
    this->name = name;
    capacity = 0;
    this->location = location;
    students = 0;
}


Campus::setCapacity(string capacity)
{
    this->capacity = capacity;
}

Campus::setLocation(string location)
{
    this->location = location;
}

Campus::getCapacity(
{
    return capacity;
}

Campus:getLocation()
{
    return location;
}


Campus::addStudents(int students)
{
    int available = capacity - this->students;
    if (available <= students){
        this->students += students;
    } else{
        if (available > 0){
            this->students = capacity;
            cout << "SE LLENARON LOS CUPOS" << endl;
            cout << "Sólo se pudo agregar a " << available << " estudiantes";
        } else{
            cout << "Ya no caben estudiantes";
        }    
    }
}

Campus::addProgram(Program program)
{
    programs.push_back(program);
}

Campus::printPrograms()
{
    
    for (auto program : programs){
        cout << program.name << " " << program.area << endl;
    }
        
}

Campus::print(){
    cout << "\nNombre del campus: " << name << endl;
    cout << "Localidad del campus: " << location << endl;
    cout << "Capacidad: " << capacity << endl;
    cout << "Estudiiantes: " << capacity << endl;
}

//#endif