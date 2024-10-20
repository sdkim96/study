#ifndef CPPARRAY_H
#define CPPARRAY_H
#include <iostream>

class CppArray {

    public:
        CppArray(int size, float initValue);
        CppArray(const CppArray &cppArray);
        
        ~CppArray();

        CppArray operator=(const CppArray &cppArray);
        CppArray operator&(const CppArray &cppArray);
        float &operator[](int index);

        int getSize();

        friend std::ostream &operator<<(std::ostream &out, const CppArray &cppArray);
        friend std::istream &operator>>(std::istream &in, CppArray &cppArray); 
    
    private:
        int size;
        float *array;

};


#endif //CPPARRAY_H