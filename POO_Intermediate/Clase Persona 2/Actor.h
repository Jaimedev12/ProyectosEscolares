#include "Person.h"

class Actor : public Person{
private:
    int oscarAwards;
    string lastMovie;

public:
    Actor();
    Actor(string, int, string, int, string);

    void showData();
    void cry();
};

Actor::Actor() : Person(){
    oscarAwards = 0;
    lastMovie = "";
}

Actor::Actor(string name, int age, string nationality, int oscarAwards, string lastMovie) : Person(name, age, nationality){
    this->oscarAwards = oscarAwards;
    this->lastMovie = lastMovie;
}

void Actor::showData(){
    cout << "-------TIPO ACTOR-------" << endl;
    cout << "Nombre: " << name;
    cout << "\t\tEdad: " << age;
    cout << "\t\tNacionalidad: " << nationality;
    cout << "\t\tNúmero de Óscares: " << oscarAwards;
    cout << "\t\tÚltima película: " << lastMovie << endl;
}

void Actor::cry(){
    cout << "*" << name << " crying in spanish*" << endl;
}