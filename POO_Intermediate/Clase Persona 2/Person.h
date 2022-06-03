#ifndef PERSON_H
#define PERSON_H


#include <iostream>

using namespace std;

class Person {

protected:
    string name;
    int age;
    string nationality;
    
public:
    Person();
    Person(string, int, string);

    virtual void showData();
};

Person::Person(){
    name = "";
    age = 0;
    nationality = "";
}

Person::Person(string name, int age, string nationality){
    this->name = name;
    this->age = age;
    this->nationality = nationality;
}

void Person::showData(){
    cout << "-------TIPO PERSONA-------" << endl;
    cout << "Nombre: " << name;
    cout << "\t\tEdad: " << age;
    cout << "\t\tNacionalidad: " << nationality << endl;
}

#endif