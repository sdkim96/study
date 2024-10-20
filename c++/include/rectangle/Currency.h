#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>

class Currency {

    public:
        Currency(int d, int c);
        ~Currency();

        Currency operator+(const Currency &c);
        Currency operator-(const Currency &c);

        friend std::ostream &operator<<(std::ostream &os, const Currency &c);

    private:    
        int dollars;
        int cents;
    
};

#endif // CURRENCY_H
