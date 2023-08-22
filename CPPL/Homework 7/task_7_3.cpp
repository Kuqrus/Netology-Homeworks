#include "task_7_3.h"

void task_7_3() {
    try
    {
        vectoriya<int> test(2);
        std::cout << "Current size: " << test.Size() << ", Current capacity: " << test.Capacity() << std::endl;

        test.Push_back(2);
        test.Push_back(5);
        std::cout << "Value at index 0: " << test.At(0) << "\nValue at index 1: " << test.At(1) << std::endl;

        test.Push_back(55); std::cout << "Value at index 2: " << test.At(2) << std::endl;
        std::cout << "Current size: " << test.Size() << ", Current capacity: " << test.Capacity() << std::endl;


        test.Push_back(22);
        test.Push_back(5515);
        std::cout << "Value at index 3: " << test.At(3) << "\nValue at index 4: " << test.At(4) << std::endl;
        std::cout << "Current size: " << test.Size() << ", Current capacity: " << test.Capacity() << std::endl;

        vectoriya<int> copy;

        copy = test;
        std::cout << "Value at index 3: " << copy.At(3) << "\nValue at index 4: " << copy.At(4) << std::endl;
        std::cout << "Current size: " << copy.Size() << ", Current capacity: " << copy.Capacity() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}