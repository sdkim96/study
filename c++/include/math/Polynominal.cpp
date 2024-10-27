#include "Polynomial.h"

Polynomial::Polynomial(int c, int t) {
    this->capacity = c;
    this->terms = t;

    this->termArray = new Term[capacity];
};

Polynomial::~Polynomial() {
    delete[] termArray;
};

// 복사 생성자
Polynomial::Polynomial(const Polynomial& other) {
    capacity = other.capacity;
    terms = other.terms;
    termArray = new Term[capacity]; // 새로운 메모리 할당
    for (int i = 0; i < terms; ++i) {
        termArray[i] = other.termArray[i]; // 각 항을 복사
    }
}

Polynomial Polynomial::operator=(const Polynomial &otherPoly) {
    // deep copy
    if (this == &otherPoly) return *this;

    delete[] termArray;
    this->termArray = new Term[otherPoly.capacity];
    this->capacity = otherPoly.capacity;
    this->terms = otherPoly.terms;

    for (int i=0; i<terms; i++) {
        termArray[i] = otherPoly.termArray[i];
    }

    return *this;

};



int main() {

    int capacity = 10;
    int terms = 2;

    Polynomial poly = Polynomial(capacity, terms);
}