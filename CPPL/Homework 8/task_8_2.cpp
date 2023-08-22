#include "task_8_2.h"


template<class T>
void PrintContainer(T& container) {
    if (typeid(T) != typeid(std::set<std::string>) &&
        typeid(T) != typeid(std::vector<std::string>) &&
        typeid(T) != typeid(std::list<std::string>)) {
        std::cerr << "Invalid data type!" << std::endl;
        return;
    }
    for (const auto el : container) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void task_8_2() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    PrintContainer(test_set);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    PrintContainer(test_vector);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    PrintContainer(test_list);


    std::array<int, 5> test_container_int = { 1,2,3,4,5 };
    //std::set<int> test_container_int = { 1,2,3,4,5 };    
    PrintContainer(test_container_int);

    //int* test = new int[4] {1, 2, 3, 4};
    //int test = 3;
    //std::string test = "test";
    //PrintContainer(test);
}