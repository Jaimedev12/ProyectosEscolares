#include "Person.h"

#ifndef Person.h

class Teacher : public Person{
private:
    string department;

public:
    Teacher();
    Teacher(string _name, int _age, string _department);

    void applyTest();
};

Teacher::Teacher() : Person(){
    department = "";
}

Teacher::Teacher(string _name, int _age, string _department) : Person(_name, _age){
    department = _department;
}

void Teacher::applyTest(){
    cout << endl << name << " aplicando examen...";
}

#endif Person.h