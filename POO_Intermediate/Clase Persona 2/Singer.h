#include <vector> 

#include "Person.h"

class Singer : public Person{
private:
    string gender;

public: 
    Singer();
    Singer(string, int, string, string);

    void showData();
    void sing();

};

Singer::Singer() : Person(){
    gender = "";
}

Singer::Singer(string name, int age, string nationality, string gender) : Person(name, age, nationality){
    this->gender = gender;
}

void Singer::showData(){
    cout << "-------TIPO CANTANTE-------" << endl;
    cout << "Nombre: " << name;
    cout << "\t\tEdad: " << age;
    cout << "\t\tNacionalidad: " << nationality;
    cout << "\t\tGénero: " << gender << endl;
}

void Singer::sing(){
    cout << "Compa me gusta su vieja... *suena tuba*" << endl;
}
