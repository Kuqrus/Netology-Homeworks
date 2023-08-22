#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "rus");

    std::vector<int> v = { 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: " << std::endl;
    std::for_each(v.begin(), v.end(), [](int i) {std::cout << i << " "; });
    std::cout << std::endl;

    auto func_ = [&v](int& i) {
        if (i % 2 != 0) {
            i *= 3;
        }        
    };
    std::for_each(v.begin(), v.end(), func_);

    std::cout << "Выходные данные: " << std::endl;
    std::for_each(v.begin(), v.end(), [](int i) {std::cout << i << " "; });
}
