#include "Person.h"

class Student : public Person{
private:
    string program;

public:
    Student();
    Student(string _name, int _age, string _program);

    void study();
};

Student::Student() : Person(){
    program = "";
}

Student::Student(string _name, int _age, string _program) : Person(_name, _age){
    program = _program;
}

void Student::study(){
    cout << endl << name << " Estudiando..." << endl;
}
