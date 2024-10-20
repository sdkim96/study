#include "CppArray.h"
#include <iostream>

CppArray::CppArray(int size, float initValue) {
    this->size = size;
    this->array = new float[size];
    
    for (int i=0; i<size; i++) {
        this->array[i] = initValue;
    };
};

CppArray::CppArray(const CppArray &cppArray) {

    for (int i=0; i<cppArray.size; i++) {
        this->array[i] = cppArray.array[i];
    };
};

CppArray::~CppArray() {
    delete[] array;
};

CppArray CppArray::operator=(const CppArray &cppArray) {
    // 이거 좀 어려움

    // 만약 두개가 같은 주소값을 가리키고 있으면 리턴
    if (this == &cppArray) return *this;

    // 기존꺼 소멸 시키고
    delete[] array;

    // hard copy 해야함 아니면 
    this->size = cppArray.size;
    this->array = new float[this->size];

    for (int i=0; i<cppArray.size; i++) {
        this->array[i] = cppArray.array[i];
    }

    return *this;
}