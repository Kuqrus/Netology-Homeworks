#include <iostream>


int main() {

    int num = 15;

    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int left = 0;
    int middle = 0;
    int right = size - 1;

    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] <= num) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    int summ = size - left;

    std::cout << "numbers larger than " << num << " in array: " << summ << std::endl;
}