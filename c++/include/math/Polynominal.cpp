#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial(int c) {
    std::cout << "Polynomial.cpp: construct polynomial with capacity and terms" << std::endl;

    this->capacity = c;
    this->termArray = new Term[this->capacity]; // 길이 terms만큼의 Temp 배열 생성

    for (int i=0; i<this->capacity; i++) {
        this->termArray[i].coef = 0.0;
        this->termArray[i].exp = 0;
    }
};

// 복사 생성자
Polynomial::Polynomial(const Polynomial& other) {
    std::cout << "Polynomial.cpp: construct polynomial with other polynomial" << std::endl;

    this->capacity = other.capacity;
    this->termArray = new Term[this->capacity]; // 길이 terms만큼의 Temp 배열 생성

    for (int i=0; i<this->capacity; i++) {
        this->termArray[i].coef = other.termArray[i].coef;
        this->termArray[i].exp = other.termArray[i].exp;
    }
}

Polynomial::~Polynomial() {
    std::cout << "Polynomial.cpp: destruct polynomial" << std::endl;
    delete[] termArray;
};

Polynomial &Polynomial::setTerm(float coef, int exp) {
    std::cout << "Polynomial.cpp: setEachTerm called" << std::endl;

    Term *thisArray = this->termArray;

    int curretCapa = 0;
    int isExist = 1;

    do {
        if (
            thisArray[curretCapa].coef == 0.0f 
            && thisArray[curretCapa].exp == 0
        ) {isExist = 0;}
        else {
            curretCapa++;
        }
    } while (isExist);

    thisArray[curretCapa].coef = coef;
    thisArray[curretCapa].exp = exp;

    return *this;
}

Polynomial& Polynomial::operator=(const Polynomial &otherPoly) {
    
    // deep copy

    if (this != &otherPoly) {
        delete[] this->termArray;

        this->capacity = otherPoly.capacity;
        this->termArray = new Term[this->capacity];

        for (int i=0; i<this->capacity; i++) {
            this->termArray[i].coef = otherPoly.termArray[i].coef;
            this->termArray[i].exp = otherPoly.termArray[i].exp;
        }
    }

    return *this;
};


CompareResult Polynomial::isCapacityBiggerThan (const Polynomial &otherPoly) {
    std::cout << "Polynomial.cpp: isCapacityBiggerThan called" << std::endl;

    if (this->capacity > otherPoly.capacity) {
        return CompareResult::isBigger;
    } else if (this->capacity < otherPoly.capacity) {
        return CompareResult::isSmaller;
    } else {
        return CompareResult::isEqual;
    }
}


/*

    예를 들어서
    3x^8 + 2x^5 + 1x^3 + 5x^1 + 9x^0 를 객체로 표현하면
    [Term(3.0, 8), Term(2.0, 5), Term(1.0, 3), Term(5.0, 1), Term(9.0, 0)]
    이런 식인데




*/

Polynomial Polynomial::add(const Polynomial &otherPoly) {
    std::cout << "Polynomial.cpp: add called" << std::endl;

    int newCapacity;
    CompareResult result = this->isCapacityBiggerThan(otherPoly);

    switch (result) {
        case CompareResult::isBigger:
            newCapacity = this->capacity;
            break;
        case CompareResult::isSmaller:
            newCapacity = otherPoly.capacity;
            break;
        case CompareResult::isEqual:
            newCapacity = this->capacity;
            break;
    }

    Polynomial newPoly = Polynomial(newCapacity);

    for (int i=0; i<newCapacity; i++) {
         
        //TODO: 이 부분을 다시 생각해보자 정확하지 않음
        if (this->termArray[i].exp == otherPoly.termArray[i].exp) {
            newPoly.setTerm(this->termArray[i].coef + otherPoly.termArray[i].coef, this->termArray[i].exp);
        } else {
            newPoly.setTerm(this->termArray[i].coef, this->termArray[i].exp);
            newPoly.setTerm(otherPoly.termArray[i].coef, otherPoly.termArray[i].exp);
        }
    }

    return *this;
}

Polynomial Polynomial::subtract(const Polynomial &otherPoly) {
    std::cout << "Polynomial.cpp: substract called" << std::endl;

    return *this;
}

Polynomial Polynomial::multiply(const Polynomial &otherPoly) {
    std::cout << "Polynomial.cpp: multiply called" << std::endl;

    return *this;
}


int main() {


    return 0;
}