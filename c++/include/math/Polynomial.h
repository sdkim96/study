#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

enum class CompareResult {
    isBigger,
    isSmaller,
    isEqual
};

class Polynomial {

    public:
        Polynomial(int c);
        Polynomial(const Polynomial& other);
        ~Polynomial();

        Polynomial& setTerm(float coef, int exp);

        Polynomial& operator=(const Polynomial &p);

        Polynomial add(const Polynomial &otherPoly);
        Polynomial subtract(const Polynomial &otherPoly);
        Polynomial multiply(const Polynomial &otherPoly);
        

    private:
        CompareResult isCapacityBiggerThan(const Polynomial &otherPoly);
        Term *termArray;
        int capacity; // 미리 할당된 배열의 크기 (나중에 커질 수 있으니)

};

class Term {

    friend Polynomial;
    private:
        float coef;
        int exp;
}; // [Term(3.5, 2), Term(2.5, 1), Term(1.5, 0), Term(-5.7, 9)] -> termArray


#endif // POLYNOMIAL_H
