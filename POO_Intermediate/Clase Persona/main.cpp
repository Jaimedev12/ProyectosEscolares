#include <iostream>
using namespace std;

//#include "Person.h"
#include "Student.h"
#include "Teacher.h"


int main(){

    Person pers1("Jaime", 18), pers2, pers3("Yuyis", 19);
    Student est1, est2("Andrea", 19, "ITC"), est3("Rolis", 18, "IQ");
    Teacher teach1("Tere Garza", 35, "ICT"), teach2("unverto", 40, "IIT"), teach3;

    cout << "Mostrando datos de personas: " << endl;
    pers1.showData();
    pers2.showData();
    pers3.showData();

    cout << "Mostrando datos de estudiantes: " << endl;
    est1.showData();
    est2.showData();
    est3.showData();

    cout << "Mostrando datos de maestr@s: " << endl;
    teach1.showData();
    teach2.showData();
    teach3.showData();

  return 0;
}
