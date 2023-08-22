#include <iostream>
#include <variant>

#include "lib.h"

void printString(std::string& s) {
    std::cout << s;
}

void printNums(std::variant<int, double> n) {
    if (std::holds_alternative<int>(n)) {
        int i = std::get<int>(n);
        std::cout << "Integer: " << i;
    }
    else if (std::holds_alternative<int>(n)) {    // Скопировали блок if-else и забыли поменять условие - семантическая ошибка
    //else if (std::holds_alternative<double>(n)) {
        double i = std::get<double>(n);
        std::cout << "Double: " << i;
    }
}

int main()
{

    std::string s = 'Hello world!';               // Пришел питонист и вместо двойных кавычек поставил одинарные - синтаксическая ошибка
    //std::string s = "Hello world!";    
    printString(s);

    std::cout << std::endl;

    double num = 5.2;
    printNums(num);

    std::cout << std::endl;

    veryComplexFunctionName();
}