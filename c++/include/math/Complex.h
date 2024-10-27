#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {

    public:
        
        Complex(double r, double i);
        Complex();
        ~Complex();

        Complex operator+(const Complex &c);
        Complex operator-(const Complex &c);
        Complex operator*(const Complex &c);

        friend std::ostream &operator<<(std::ostream &os, const Complex &c);

    private:
        double real;
        double imag;
};


#endif // COMPLEX_H
