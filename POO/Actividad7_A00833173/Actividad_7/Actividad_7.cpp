// Actividad 7 - A008331733
// Jaime Eduardo López Castro

#include <iostream>
#include <cstdlib>
#include "Fraccion.h"
using namespace std;

int MCD(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return MCD(a - b, b);
    else return MCD(a, b - a);
}

int mcm(int a, int b) {
    return ((a * b) / MCD(a, b));
}

Fraccion* sumaFracciones(Fraccion* fracc1, Fraccion* fracc2) {
    int num1, den1;
    int num2, den2;

    num1 = fracc1->getNum();
    num2 = fracc2->getNum();

    den1 = fracc1->getDen();
    den2 = fracc2->getDen();
    
    //finding lcm of the denominators
    int lcm = mcm(den1, den2);
    
    //finding the sum of the numbers
    int sum = (num1 * lcm / den1) + (num2 * lcm / den2);
    
    //normalizing numerator and denominator of result
    int num3 = sum / MCD(sum, lcm);
    lcm = lcm / MCD(sum, lcm);
    
    //printing output
    cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << num3 << "/" << lcm;

    Fraccion* nuevaFraccion = new Fraccion(num3, lcm);

    return nuevaFraccion;
}


/*
Fraccion* sumaFracciones(Fraccion* fracc1, Fraccion* fracc2) {
    Fraccion* nuevaFraccion = new Fraccion();
    int nuevoDen, nuevoNum;
    double nuevoNum1, nuevoNum2;
    nuevoDen = mcm(fracc1->getDen(), fracc2->getDen());
    nuevoNum1 = ((static_cast<double>(fracc1->getDen()) / nuevoDen) * fracc1->getNum());
    nuevoNum2 = ((static_cast<double>(fracc2->getDen()) / nuevoDen) * fracc2->getNum());
    nuevoNum = nuevoNum1 + nuevoNum2;

    nuevaFraccion->setDen(nuevoDen);
    nuevaFraccion->setNum(nuevoNum);

    return nuevaFraccion;
}
*/

//--------------------------------------------------------------------------------------------------------------

int main()
{
    int numDeFracciones = 0;
    int num, den;
    int index1, index2, index3;
    cout << "Ingresa el numero de fracciones del arreglo: ";
    cin >> numDeFracciones;

    while (numDeFracciones < 5) {
        cout << "El numero tiene que ser mayor o igual a 5, intenta de nuevo: ";
        cin >> numDeFracciones;
    }

    Fraccion* arrFracc[20];

    for (int indiceFraccion = 0; indiceFraccion < numDeFracciones; indiceFraccion++)
    {
        int nuevoNum, nuevoDen;
        cout << "Fraccion " << indiceFraccion + 1 << endl;
        cout << "Ingresa el numerador: ";
        cin >> nuevoNum;

        cout << "Ingresa el denominador: ";
        cin >> nuevoDen;

        while (nuevoDen == 0) {
            cout << "El denominador no puede ser 0, intentalo de nuevo: ";
            cin >> nuevoDen;
        }

        arrFracc[indiceFraccion] = new Fraccion(nuevoNum, nuevoDen);
    }



    index1 = rand() % numDeFracciones;
    index2 = rand() % numDeFracciones;
    index3 = rand() % numDeFracciones;

    Fraccion* suma = new Fraccion();
    suma = sumaFracciones(sumaFracciones(arrFracc[index1], arrFracc[index2]), arrFracc[index3]);

    suma->imprimeFraccion();
}
