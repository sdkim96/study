#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {

    public:
        Polynomial(int c, int t);
        ~Polynomial();

        Polynomial operator=(const Polynomial &p);

        Polynomial add();
        Polynomial subtract();

    private:
        Term *termArray;
        int capacity; // 미리 할당된 배열의 크기 (나중에 커질 수 있으니)
        int terms; // 다항식의 항의 개수

};

class Term {

    friend Polynomial;
    private:
        float coef;
        int exp;
}; // [Term(3.5, 2), Term(2.5, 1), Term(1.5, 0)] -> termArray


#endif // POLYNOMIAL_H
