#include <iostream>
#include <vector>


void merge_arrays(int left[], int left_size, int right[], int right_size, int* arr) {
    int lI = 0, rI = 0, aI = 0;
    while (lI < left_size && rI < right_size) {
        if (left[lI] <= right[rI]) {
            arr[aI] = left[lI];
            aI++;
            lI++;
        }
        else {
            arr[aI] = right[rI];
            aI++;
            rI++;
        }
    }
    while (lI < left_size) {
        arr[aI] = left[lI];
        aI++;
        lI++;
    }
    while (rI < right_size) {
        arr[aI] = right[rI];
        aI++;
        rI++;
    }
}

void merge_sort(int* arr, int size) {
    if (size <= 1) return;
    int size_left = size / 2;
    int size_right = size - size_left;
    int* left = new int[size_left];
    int* right = new int[size_right];
    for (int i = 0; i < size / 2; i++) {
        left[i] = arr[i];
    }
    for (int i = size / 2; i < size; i++) {
        right[i - (size / 2)] = arr[i];
    }
    merge_sort(left, size_left);
    merge_sort(right, size_right);
    merge_arrays(left, size_left, right, size_right, arr);
    delete[] left;
    delete[] right;
}

void quick_sort(int* arr, int size) {
    if (size <= 1) return;
    int r = size - 1;
    int l = 0;
    int pivot = (r + l) / 2;    
    do
    {        
        while (arr[l] < arr[pivot]) {
            l++;
        }
        while (arr[r] > arr[pivot]) {
            r--;
        }
        if (l <= r) {
            std::swap(arr[l], arr[r]);
            l++;
            r--;
        }

    } while (l <= r);

    if (r > 0) {
        quick_sort(arr, r + 1);
    }
    if (l < size) {
        quick_sort(&arr[l], size - l);
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
    setlocale(LC_ALL, "rus");
    
    {
        // Сортировка слиянием

        int arr_1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
        int size_1 = sizeof(arr_1) / sizeof(arr_1[0]);
        std::cout << "До сортировки: ";
        printArr(arr_1, size_1);
        merge_sort(arr_1, size_1);
        std::cout << "После сортировки: ";
        printArr(arr_1, size_1);
        std::cout << std::endl;

        int arr_2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
        int size_2 = sizeof(arr_2) / sizeof(arr_2[0]);
        std::cout << "До сортировки: ";
        printArr(arr_2, size_2);
        merge_sort(arr_2, size_2);
        std::cout << "После сортировки: ";
        printArr(arr_2, size_2);
        std::cout << std::endl;

        int arr_3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
        int size_3 = sizeof(arr_3) / sizeof(arr_3[0]);
        std::cout << "До сортировки: ";
        printArr(arr_3, size_3);
        merge_sort(arr_3, size_3);
        std::cout << "После сортировки: ";
        printArr(arr_3, size_3);
        std::cout << std::endl;
    }


    {
        // Быстрая сортировка

        /*int arr_1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
        int size_1 = sizeof(arr_1) / sizeof(arr_1[0]);
        std::cout << "До сортировки: ";
        printArr(arr_1, size_1);
        quick_sort(arr_1, size_1);
        std::cout << "После сортировки: ";
        printArr(arr_1, size_1);
        std::cout << std::endl;

        int arr_2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
        int size_2 = sizeof(arr_2) / sizeof(arr_2[0]);
        std::cout << "До сортировки: ";
        printArr(arr_2, size_2);
        quick_sort(arr_2, size_2);
        std::cout << "После сортировки: ";
        printArr(arr_2, size_2);
        std::cout << std::endl;

        int arr_3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
        int size_3 = sizeof(arr_3) / sizeof(arr_3[0]);
        std::cout << "До сортировки: ";
        printArr(arr_3, size_3);
        quick_sort(arr_3, size_3);
        std::cout << "После сортировки: ";
        printArr(arr_3, size_3);
        std::cout << std::endl;*/
    }

}