#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string userName = "";

    std::cout << "Введите имя: ";
    std::cin >> userName;

    std::cout << std::endl << "Здравствуйте, " << userName << "!" << std::endl;

}