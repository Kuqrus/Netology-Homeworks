#include <iostream>
#include "leaver.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string userName;

    std::cout << "Введите имя: ";
    std::cin >> userName;

    Leaver leave;
    leave.bye(userName);

    system("pause");

}