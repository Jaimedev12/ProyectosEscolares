#include <iostream>

using namespace std;

class Person{

    private:
        string name;
        int freeHours;

    public:
        Person();
        Person(string, int);

        Person operator+(Person pers2);

        void showData();
};

Person::Person(){
    name = "";
    freeHours = 0;
}

Person::Person(string name, int freeHours){
    this->name = name;
    this->freeHours = freeHours;
}

Person Person::operator+(Person pers2){
    string names = name + " + " + pers2.name;
    int totalHours = freeHours + pers2.freeHours;

    return Person(names, totalHours);
}


void Person::showData(){
    cout << "Nombre: " << name << endl;
    cout << "Horas libres: " << freeHours << endl;
}