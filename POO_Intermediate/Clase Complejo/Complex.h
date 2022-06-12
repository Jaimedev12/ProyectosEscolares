#include <iostream>

using namespace std;

class Complex{
    private:
        int real;
        int imag;

    public:
        Complex();
        Complex(int, int);

        Complex operator+(Complex c2);
        Complex operator-(Complex c2);

        void showData();

};

Complex::Complex(){
    int real = 0;
    int imag = 0;
}

Complex::Complex(int real, int imag){
    this->real = real;
    this->imag = imag;
}

Complex Complex::operator+(Complex c2){
    int realN = real + c2.real;
    int imagN = imag + c2.imag;

    Complex newComplex(realN, imagN);

    return newComplex;
}

Complex Complex::operator-(Complex c2){
    int realN = real - c2.real;
    int imagN = imag - c2.imag;

    Complex newComplex(realN, imagN);

    return newComplex;
}

void Complex::showData(){

    cout << real << " + " << imag << "i" << endl;
    //cout << "Parte real: " << real << endl;
    //cout << "Parte imaginaria: " << imag << endl;
}