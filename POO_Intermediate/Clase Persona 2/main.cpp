#include "Singer.h"
#include "Actor.h"

int main(){

    Person pers1, pers2("Jaime", 18, "Mexicano"), pers3("Andrea", 19, "Mexicana");

    Singer sing1, sing2("Talía", 25, "Mexicana", "Punk Neoporfirista"), 
    sing3("Baboni", 24, "Mundial", "Baladas Románticas");

    Actor act1, act2("Brus Wilis", 84, "Yucateco", 21, "Shrek 2"), 
    act3("La Roca", 32, "Mochitense", 3, "Una Niñera Aprueba de Balas");

// -----------PERSONAS------------------
    pers2.showData();
// -------------------------------------

    cout << endl << endl;

// -----------CANTANTES------------------
    sing3.showData();
    cout << endl;
    sing3.sing();
// --------------------------------------

    cout << endl << endl;

// -----------ACTORES------------------
    act2.showData();
    cout << endl;
    act2.cry();
// ------------------------------------


    
    vector<Person*> personList;

    personList.push_back(&pers1);
    personList.push_back(&pers2);
    personList.push_back(&pers3);
    personList.push_back(&sing1);
    personList.push_back(&sing2);
    personList.push_back(&sing3);
    personList.push_back(&act1);
    personList.push_back(&act2);
    personList.push_back(&act3);
    

    cout << endl << endl << "----------- Lista ----------- " << endl << endl;


    /*
    Person *personList[10];
    personList[0] = &pers1;
    personList[1] = &pers2;
    personList[2] = &pers3;
    personList[3] = &act1;
    personList[4] = &act2;
    personList[5] = &act3;
    personList[6] = &sing1;
    personList[7] = &sing2;
    personList[8] = &sing3;
    personList[9] = &pers1;
    */

    for (int i = 0; i < 10; i++){
        personList[i] -> showData();
    }




    return 0;
}