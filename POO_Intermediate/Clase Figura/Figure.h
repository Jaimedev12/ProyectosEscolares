#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

using namespace std;

class Figure{
protected:
    int x, y;

public:
    Figure();
    virtual void draw() = 0;
};

Figure::Figure(){
    x, y = 1;
}

#endif