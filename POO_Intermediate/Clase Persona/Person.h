#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person{
protected:
  string name;
  int age;

public:
    Person();
    Person(string _name, int _age);

  // Setters y getters
  void showData();
  void sing();

};

Person::Person(){
    name = "";
    age = 0;
}

Person::Person(string _name, int _age){
    name = _name;
    age = _age;
}

void Person::showData(){
    cout << endl << "Datos de la persona: " << endl;
    cout << "Nombre: " << name << endl;
    cout << "Edad: " << age << endl;
}

void Person::sing(){
  cout << endl << name << " cantando..." << endl;
}

#endif