#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string userName = "";

    std::cout << "������� ���: ";
    std::cin >> userName;

    std::cout << std::endl << "������������, " << userName << "!" << std::endl;

}