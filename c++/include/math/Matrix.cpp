#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->smArray = new MatrixTerm[rows * cols]; // 길이 rows * cols인 배열 생성
};

Matrix::~Matrix() {
    delete[] smArray;
};

Matrix Matrix::transpose() {
    
    Matrix transposedMatrix = Matrix(this->cols, this->rows);

    int termElements = this->rows * this->cols;

    for (int i=0; i<termElements; i++) {
        transposedMatrix.smArray[i].rowPosition = this->smArray[i].colPosition;
        transposedMatrix.smArray[i].colPosition = this->smArray[i].rowPosition;
        transposedMatrix.smArray[i].thatValue = this->smArray[i].thatValue;
    }
};