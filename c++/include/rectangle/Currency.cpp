#include "Currency.h"


Currency::Currency(int d, int c) {

    if (c > 100) {
        d += c / 100;
        c = c % 100;
    };
    
    this->dollars = d;
    this->cents = c;
};


Currency::~Currency() {

};

Currency Currency::operator+(const Currency &c) {
    int newDollar = this->dollars + c.dollars;
    int newCents = this->cents + c.cents;

    if (newCents > 100) {
        newDollar += 1;
        newCents -= 100;
    };

    return Currency(newDollar, newCents);
};

Currency Currency::operator-(const Currency &c) {
    int newDollar = this->dollars - c.dollars;
    int newCents = this->cents - c.cents;

    if (newCents < 0) {
        newDollar -= 1;
        newCents += 100;
    };

    return Currency(newDollar, newCents);
};

std::ostream &operator<<(std::ostream &os, const Currency &c) {
    os << "$" << c.dollars << "." << c.cents;
    return os;
};