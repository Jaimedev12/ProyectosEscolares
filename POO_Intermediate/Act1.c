#include <iostream>
#include <string>

using namespace std;

class Person{

  private:
      string name;
      int age;
      double mass;
      double height;

  public:
      Person();
      Person(string name, int age, double mass, double height);

      void showData();
      void sing();
      double calcIMC();

};

Person::Person(){
    this->name = "";
    this->age = NULL;
    this->mass = NULL;
    this->height = NULL;
}

Person::Person(string name, int age, double mass, double height){
    this->name = name;
    this->age = age;
    this->mass = mass;
    this->height = height;

}

void Person::showData(){
    cout << "Nombre: " << this->name << endl;
    cout << "Edad: " << this->age << " años" << endl;
    cout << "Peso: " << this->mass << " kilos" << endl;
    cout << "Estatura: " << this->height << " metros" << endl;
}

void Person::sing(){
    cout << "Estas son las mañanitas chalalá chalalá" << endl;
}

double Person::calcIMC(){
    return this->mass/(this->height * this->height);
}

int main(){

    Person person1("Jaime", 18, 70, 1.70);
    person1.showData();
    person1.sing();
    cout << "IMC: "<< person1.calcIMC();

    return 0;

}
