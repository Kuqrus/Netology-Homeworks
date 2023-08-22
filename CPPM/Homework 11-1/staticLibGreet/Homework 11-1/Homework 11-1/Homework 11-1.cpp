#include <iostream>
#include "greeter.h"
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string userName;

    std::cout << "Введите имя: ";
    std::cin >> userName;

    Greeter hello;
    hello.greet(userName);

    system("pause");

}
