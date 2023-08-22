#include <iostream>

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int memoryFib[10] = { 0 };

int fib_mem(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    if (memoryFib[n] == 0) {
        memoryFib[n] = fib_mem(n - 1) + fib_mem(n - 2);
    }
    return memoryFib[n];
}

int fib_arr(int n) {
    int* arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

void fillArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = fib_arr(i);
        //arr[i] = fib_mem(i);
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    int size = 10;
    int* arrFR = new int[size];  

    fillArr(arrFR, size);
    printArr(arrFR, size);

    delete[] arrFR;
}
