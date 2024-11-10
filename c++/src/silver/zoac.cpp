#include <iostream>
#include <vector>


// https://www.acmicpc.net/problem/23971
int main() {

    int row, column, rowDistance, columnDistance;

    std::cin >> row;
    std::cin >> column;

    std::cin >> rowDistance;
    std::cin >> columnDistance;

    // rule
    // 일단 작은 리스트에 다 넣음
    
    // 1. 아주 큰 리스트 하나를 만들고 초기화
    int size = row * column;
    int *array = new int[size];
    for (int i=0; i<size; i++) {
        array[i] = 0;
    }

    int sum = 0;


    //2. 칼럼 방향으로 초기화
    int *smallArray = new int[column];

    for (int i=0; i<column; i++) {
        smallArray[i] = (i % (columnDistance+1) == 0)? 1 : 0;
    }

    // 3. 아주 큰 리스트에 초기화
    for (int i = 0; i < row; i++) {
        // rowDistance 조건에 따라 행을 필터링
        if (i % (rowDistance + 1) != 0) continue;

        for (int j = 0; j < column; j++) {
            array[i * column + j] = smallArray[j];
        }
    }

    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
        if (i % column == column - 1) {
            std::cout << std::endl;
        }
        if (array[i] == 1) sum++;
    }

    std::cout<< sum << std::endl;

    delete[] array;
    delete[] smallArray;

    return 0;
}