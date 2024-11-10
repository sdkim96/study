#include <iostream>

void bubbleSort(int *arr, int size) {

    bool swap = true;
    while (swap) {
        swap = false;

        for (int i=0; i< size -1 ; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = true;
            } 
        }
    }
};


int main() {

    // 1. 쉬운 인트 타입으로 
    int arr[5] = {6,9,3,8,5};
    bubbleSort(arr, 5);

    return 0;
}