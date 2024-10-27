#ifndef DIFFERENTIAL_H
#define DIFFERENTIAL_H

class Differential {
    
    public:
        Differential();
        ~Differential();

        Differential operator=(const Differential &d);

        Differential add();
        Differential subtract();

    private:
        float *diffArray;
        int capacity; // 미리 할당된 배열의 크기 (나중에 커질 수 있으니)
        int diffs; // 미분식의 항의 개수

};

#endif // DIFFERENTIAL_H
