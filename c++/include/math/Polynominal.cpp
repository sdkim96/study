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

Polynomial Polynomial::add(const Polynomial &otherPoly) {
    std::cout << "Polynomial.cpp: add called" << std::endl;

    int newCapacity = this->capacity + otherPoly.capacity;
    Polynomial newPoly(newCapacity);

    int i = 0, j = 0, k = 0;

    while (i < this->capacity && j < otherPoly.capacity) {
        if (this->termArray[i].exp == otherPoly.termArray[j].exp) {
            // 동일한 지수인 경우, 계수를 더함
            float sumCoef = this->termArray[i].coef + otherPoly.termArray[j].coef;
            if (sumCoef != 0.0f) {
                newPoly.setTerm(sumCoef, this->termArray[i].exp);
            }
            i++;
            j++;
        } else if (this->termArray[i].exp > otherPoly.termArray[j].exp) {
            // this의 항이 더 높은 지수를 가지는 경우
            newPoly.setTerm(this->termArray[i].coef, this->termArray[i].exp);
            i++;
        } else {
            // otherPoly의 항이 더 높은 지수를 가지는 경우
            newPoly.setTerm(otherPoly.termArray[j].coef, otherPoly.termArray[j].exp);
            j++;
        }
    }

    // 남은 항 처리
    while (i < this->capacity) {
        newPoly.setTerm(this->termArray[i].coef, this->termArray[i].exp);
        i++;
    }

    while (j < otherPoly.capacity) {
        newPoly.setTerm(otherPoly.termArray[j].coef, otherPoly.termArray[j].exp);
        j++;
    }

    return newPoly;
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