#include "Complex.h"

Complex::Complex(double r, double i) {
    this->real = r;
    this->imag = i;
};

Complex::Complex() {
    this->real = 0;
    this->imag = 0;
};

Complex::~Complex() {

};

Complex Complex::operator+(const Complex &c) {
    int newReal = this->real + c.real;
    int newImag = this->imag + c.imag;

    return Complex(newReal, newImag);
};

Complex Complex::operator-(const Complex &c) {
    int newReal = this->real - c.real;
    int newImag = this->imag - c.imag;

    return Complex(newReal, newImag);
};

Complex Complex::operator*(const Complex &c) {
    // 복소수 곱셈 공식
    int newReal = (this->real * c.real) - (this->imag * c.imag);
    int newImag = (this->real * c.imag) + (this->imag * c.real);

    return Complex(newReal, newImag);
}

std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << c.real << " + " << c.imag << "i";
    return os;
};