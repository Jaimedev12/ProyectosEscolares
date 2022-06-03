#include <vector>

#include "Trapezium.h"
#include "Circle.h"

using namespace std;

int main (){

    Figure *arr[5];

    arr[0] = new Circle();
    arr[1] = new Trapezium();
    arr[2] = new Circle();
    arr[3] = new Trapezium();
    arr[4] = new Circle();

    Trapezium trap;
    Circle circ;

    trap.draw();
    circ.draw();


    return 0;
}