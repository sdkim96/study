#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {

    public:
        // 생성자는 처음에 사이즈만 할당
        // 어차피 벡터는 1차원 배열이므로 사이즈만 있으면 됨
        /*
        
            vector = Vector(3);
            vector.setValues([1, 2, 3]);

        
        
        
        */
        Vector(int size);
        Vector(int size, float* vectorValue);
        Vector(const Vector& otherVector);
        ~Vector();

        Vector& operator=(const Vector &v);

        Vector& getValues();
        Vector& setValues(int size, float* vectorValue);
        float getNorm();
        
        float dotProduct(const Vector& otherVector);
        float cosineSimilarity(Vector& otherVector);

    private:
        float *vectorValue;
        int size;
};



#endif // VECTOR_H