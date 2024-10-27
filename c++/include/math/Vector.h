#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {

    public:
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
