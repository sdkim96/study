#include "Vector.h"
#include <cassert>

#include <iostream>

Vector::Vector(int size) {

    /*
        주의할 점:
        Vector 안에서 동적할당을 하면, 그 메모리는 Vector이 소멸될 때 함께 소멸된다.

        Vector v = Vector(3);
        v.getValues(); // [0.0, 0.0, 0.0]

    */
    std::cout<< "Vector.cpp: construct vector with size" << std::endl;
    this->size = size;
    this->vectorValue = new float[size];

    for (int i=0; i<size; i++) {
        this->vectorValue[i] = 0.0;
    }
}; 



Vector::Vector(int size, float* vectorValue) {
    /*
        이 경우엔 vectorValue를 복사해서 새로운 메모리에 할당한다.

        float *vectorValue = new float[10]; // 10차원
        Vector v = Vector(10, vectorValue);
    */  
    std::cout<< "Vector.cpp: construct vector with size and vectorValue" << std::endl;
    
    if (vectorValue == nullptr) {
        std::cerr << "Error: Null pointer passed to setValues." << std::endl;
        
    }

    this->size = size;
    this->vectorValue = new float[size];
    for (int i=0; i<size; i++) {
        this->vectorValue[i] = vectorValue[i];
    }
};

   

Vector::Vector(const Vector& otherVector) {
    std::cout<< "Vector.cpp: construct vector with other vector" << std::endl;
    
    this->size = otherVector.size;
    this->vectorValue = new float[this->size];
    
    for (int i=0; i<this->size; i++) {
        this->vectorValue[i] = otherVector.vectorValue[i];
    }



}; // v2 = Vector(v)


Vector::~Vector() {
    std::cout<< "Vector.cpp: destruct vector" << std::endl;
    delete[] this->vectorValue;
}


Vector& Vector::operator=(const Vector &otherVector) {
    /*
        1. 대입 연산자는 자기 자신에 대한 참조를 반환해야한다.

        깊은 연산을 제공하는 = 연산자
        만약 연산자 오버로딩을 명시안하면 얕은 복사가 일어남..

        float values = new values[3];
        values[0] = 1.0;
        values[1] = 2.0;
        values[2] = 3.0;

        v1 = Vector(3, values);
        delete[] values;

        v2 = v1;
    
    */
    std::cout << "Vector.cpp: operator= called (deep copy)" << std::endl;

    // 포인터 != 참조
    if (this != &otherVector) {

        delete[] this->vectorValue; // 주소 반환

        int newSize = otherVector.size;
        float *newVectorValue = new float[newSize];

        for (int i=0; i<newSize; i++) {
            newVectorValue[i] = otherVector.vectorValue[i];
        }

    };

    return *this;
};


Vector& Vector::getValues() {
    std::cout << "Vector.cpp: getValues called" << std::endl;
    return *this;
};

Vector& Vector::setValues(int size, float* vectorValue) {
    /*
        float values = new values[4];
        int size = 3;
        values[0] = 1.0;
        values[1] = 2.0;
        values[2] = 3.0;
        values[3] = 4.0;

        vector = Vector(size);
        vector.setValues(size, values);
    
    
    */
    std::cout << "Vector.cpp: setValues called" << std::endl;

    assert(vectorValue != nullptr);
    
    this->size = size;
    for(int i=0; i<this->size; i++) {
        this->vectorValue[i] = vectorValue[i];
    }

    return *this;
    
};

float Vector::getNorm() {
    /*
        constexpr int v1Size = 6;
        float v1Value[v1Size] = {5.0, 4.0, 3.0, 2.0, 1.0, 0.0};

        Vector v1 = Vector(v1Size, v1Value);

        float norm = v1.getNorm();
    */
    std::cout << "Vector.cpp: getNorm called" << std::endl;

    float norm = 0.0f;
    
    for (int i=0; i<this->size; i++) {
        norm += this->vectorValue[i] * this->vectorValue[i];
    }

    return sqrt(norm);
}


float Vector::dotProduct(const Vector& otherVector) {
    /*  
        constexpr int v1Size = 6;
        float v1Value[v1Size] = {5.0, 4.0, 3.0, 2.0, 1.0, 0.0};

        constexpr int v2Size = 6;
        float v2Value[v2Size] = {-5.0, -4.0, -3.0, -2.0, 1.0, 9.0};

        Vector v1 = Vector(v1Size, v1Value);
        Vector v2 = Vector(v2Size, v2Value);

        float scalar = v1.dotProduct(v2);
    */
    std::cout << "Vector.cpp: dotProduct called" << std::endl;
    
    // 1. 차원 다르면 에러
    assert (this->size == otherVector.size);

    // 2. dot product 계산
    float scalar = 0.0f;

    for (int i=0; i<this->size; i++) {
        scalar += this->vectorValue[i] * otherVector.vectorValue[i];
    }

    return scalar;
    
}


float Vector::cosineSimilarity(Vector& otherVector) {

    float thisNorm = this->getNorm();
    float otherNorm = otherVector.getNorm();

    float dotted = this->dotProduct(otherVector);

    return dotted / (thisNorm * otherNorm);
}




int main() {
    const int v1Size = 6;
    float v1Value[v1Size] = {5.0, 4.0, 3.0, 2.0, 1.0, 0.0};

    const int v2Size = 6;
    float v2Value[v2Size] = {-5.0, -4.0, -3.0, -2.0, 1.0, 9.0};

    Vector v1 = Vector(v1Size, v1Value);
    Vector *v2 = new Vector(v2Size, v2Value);

    float scalar = v1.dotProduct(*v2);

    float cosineSimilarity = v1.cosineSimilarity(*v2);

    std::cout << "Dot product: " << scalar << std::endl;
    std::cout << "Cosine similarity: " << cosineSimilarity << std::endl;

    delete v2;
}