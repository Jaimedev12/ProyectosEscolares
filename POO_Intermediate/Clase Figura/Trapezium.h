#include "Figure.h"

class Trapezium : public Figure{
public:
    void draw();
};

void Trapezium::draw(){
    cout << endl;
    cout << "   ****   " << endl;
    cout << "  ******  " << endl;
    cout << " ******** " << endl;
    cout << "**********" << endl;
    cout << endl;
}
