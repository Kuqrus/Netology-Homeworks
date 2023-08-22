#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


typedef std::vector<int> vect_i;

template <class T>
T power_of_2(T x) {
    return x * x;
}

template<>
vect_i power_of_2(vect_i x) {
    std::for_each(x.begin(), x.end(), [&x](auto& i) {
        i = power_of_2(i);
        });

    return x;
}

void print(vect_i& x) {
    std::for_each(x.begin(), x.end(), [](const auto i) {
        std::cout << i << " ";
        });
    std::cout << std::endl;
}

void task_5_1() {
    std::cout << "Integer ->\n";
    int x = 5;
    std::cout << "IN: " << x << std::endl;
    std::cout << "OUT: " << power_of_2(x) << std::endl;

    std::cout << "Vector ->\n";
    vect_i xx{ -1,8,12 };
    std::cout << "IN: ";
    print(xx);

    vect_i yy = power_of_2(xx);
    std::cout << "OUT: ";
    print(yy);
}