#include <iostream>

int* create_array(int actual_size) {
    int* arr = new int[actual_size] {0};
    return arr;
}

void print_dynamic_array(int* arr, int actual_size, int logical_size) {
    std::cout << "Dynamic array: ";
    for (int i = 0; i < actual_size; i++) {        
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else std::cout << "_ ";
    }
    std::cout << std::endl;
}

void append_to_dynamic_array(int* arr, int* actual_size, int *logical_size) {    
    int new_element = 0;
    int actual = 0, logical = 0;
    while (true) {
        actual = *actual_size;
        logical = *logical_size;
        std::cout << "Enter new element: ";
        std::cin >> new_element;
        if (new_element == 0) {
            break;
        }
        if (actual <= logical) {

            int* temp_array = new int[*actual_size];
            for (int i = 0; i < *actual_size; i++) {
                temp_array[i] = arr[i];
            }

            *actual_size *=  2;
            *arr = *create_array(*actual_size);
            for (int i = 0; i < *actual_size; i++) {
                arr[i] = temp_array[i];
            }

            delete[] temp_array;

            arr[*logical_size] = new_element;
            *logical_size += 1;
        }
        else
        {
            arr[*logical_size] = new_element;
            *logical_size += 1;
        }
        print_dynamic_array(arr, *actual_size, *logical_size);
    }    
}

void remove_dynamic_array_head(int* arr, int* actual_size, int* logical_size) {
    char userAct = ' ';
    int* temp_array = new int[*actual_size];    
    while (true) {
        for (int i = 0; i < *actual_size; i++) {
            temp_array[i] = arr[i];
        }

        std::cout << "Do you want delete first element? (y/n):";
        std::cin >> userAct;

        switch (userAct)
        {
        case 'y':            
            *logical_size -= 1;
            *arr = *create_array(*actual_size);
            for (int i = 0; i < *logical_size; i++) {
                arr[i] = temp_array[i + 1];
            }            
            break;
        case 'n':
            return;
            break;
        default:
            break;
        }

        if (*logical_size <= *actual_size / 3) {
            *actual_size /= 3;
        }

        if (*logical_size == 0) {
            return;
        }

        print_dynamic_array(arr, *actual_size, *logical_size);
    }    
}

void dynamic_array() {
    int userInput = 0;
    int actualSize = 0;
    int logicalSize = 0;

    while (true) {
        std::cout << "Enter actual array size: ";
        std::cin >> actualSize;

        std::cout << "Enter logical array size: ";
        std::cin >> logicalSize;

        if (actualSize < logicalSize) {
            std::cout << "Actual size cannot be smaller then logical size!" << std::endl;
            system("cls");
        }
        else break;
    }

    int* array = create_array(actualSize);

    for (int i = 0; i < logicalSize; i++) {
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> array[i];
    }

    print_dynamic_array(array, actualSize, logicalSize);

    int userAct = 0;
    std::cout << "1. Append elements to array" << std::endl << "2. Remove dynamic array head\n";
    std::cin >> userAct;
    
    switch (userAct)
    {
    case 1:
        append_to_dynamic_array(array, &actualSize, &logicalSize);
        break;
    case 2:
        remove_dynamic_array_head(array, &actualSize, &logicalSize);
        break;
    default:
        break;
    }    

    std::cout << "Final result: " << std::endl;
    print_dynamic_array(array, actualSize, logicalSize);

}

int main()
{    
    dynamic_array();
}