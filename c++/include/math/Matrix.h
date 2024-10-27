#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {

    public:
        Matrix(int rows, int cols);
        ~Matrix();

        Matrix transpose();
        Matrix& transposeMe();

        // Matrix operator=(const Matrix &m); // deep copy
        // Matrix operator+(const Matrix &m);
        // Matrix operator-(const Matrix &m);
        // Matrix operator*(const Matrix &m);


    private:
        /*
            if rowNumbers = 7, colNumbers = 3 -> whole terms number == 3
            smArray = [
                MatrixTerm(0, 0, 0), 
                MatrixTerm(1, 0, 0), 
                MatrixTerm(2, 0, 0),
                MatrixTerm(3, 0, 0),
                MatrixTerm(4, 0, 0),
                MatrixTerm(5, 0, 0),
                MatrixTerm(6, 0, 0),
                MatrixTerm(0, 1, 0),
                MatrixTerm(1, 1, 0),
                MatrixTerm(2, 1, 0),
                MatrixTerm(3, 1, 0),
                MatrixTerm(4, 1, 0),
                MatrixTerm(5, 1, 0),
                MatrixTerm(6, 1, 0),
                MatrixTerm(0, 2, 0),
                MatrixTerm(1, 2, 0),
                MatrixTerm(2, 2, 0),
                MatrixTerm(3, 2, 0),
                MatrixTerm(4, 2, 0),
                MatrixTerm(5, 2, 0),
                MatrixTerm(6, 2, 0),
            ]

            smArray.transpose() == 
            [
                MatrixTerm(0, 0, 0), 
                MatrixTerm(0, 1, 0), 
                MatrixTerm(0, 2, 0),
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