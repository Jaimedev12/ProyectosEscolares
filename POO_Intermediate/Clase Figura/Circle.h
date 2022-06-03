#include "Figure.h"

class Circle : public Figure{
public:
    Circle();
    Circle(int r);

    void draw();
    double calcArea();
};

Circle::Circle() : Figure(){}

void Circle::draw(){
    cout << endl;
    cout << "   *****   " << endl;
    cout << " *********   " << endl;
    cout << "***********  " << endl;
    cout << " *********    " << endl;
    cout << "   ***** " << endl;
    cout << endl;
}