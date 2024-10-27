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



    return transposedMatrix;
};

Matrix& Matrix::transposeMe() {

    /*
        예를 들어 기존 메모리 주소를
        rows : (주소: aaa, 값: 3)
        cols : (주소: bbb, 값: 7)
        smArray : (주소: ccc~ )

        라고 하자. 이때 transposeMe() 함수를 호출하면
    
    */

   
    int termElements = this->rows * this->cols; // termElements (주소 : ddd, 값: 21)
    int tempRows = this->rows; // tempRows (주소: fff, 값: 3) = 3
    this->rows = this->cols; // rows (주소: aaa, 값: 7) = 7
    this->cols = tempRows; // cols (주소: bbb, 값: 3) = 3
    // 멤버변수 rows, cols 바꿈

    MatrixTerm *tempMatrixTerm = new MatrixTerm[termElements]; // tempMatrixTerm (주소: eee~ )
    /*
        rows: 7, cols: 3, smArray: (주소: zzz~ )
    */

    for (int i=0; i<termElements; i++) {
        tempMatrixTerm[i].rowPosition = this->smArray[i].colPosition;
        tempMatrixTerm[i].colPosition = this->smArray[i].rowPosition;
        tempMatrixTerm[i].thatValue = this->smArray[i].thatValue;
    };

    delete[] this->smArray; // smArray (주소: zzz~ ) 삭제
    this->smArray = tempMatrixTerm; // smArray (주소: eee~ )로 바꿈

    return *this;
};

int main() {
    Matrix m = Matrix(4,7);
    m.transpose();

}