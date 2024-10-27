#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {

    public:
        Matrix(int rows, int cols);
        ~Matrix();

        Matrix transpose(const Matrix &m);

        // Matrix operator=(const Matrix &m); // deep copy
        // Matrix operator+(const Matrix &m);
        // Matrix operator-(const Matrix &m);
        // Matrix operator*(const Matrix &m);


    private:
        /*
            if rowNumbers = 3, colNumbers = 1 -> whole terms number == 3
            smArray = [
                MatrixTerm(0, 0, 0), 
                MatrixTerm(1, 0, 0), 
                MatrixTerm(2, 0, 0),
            ]
        */
        MatrixTerm *smArray;
        int rows;
        int cols;
};

class MatrixTerm {
    friend Matrix;

    private:
        int rowPosition;
        int colPosition;
        int thatValue;
};

#endif // MATRIX_H