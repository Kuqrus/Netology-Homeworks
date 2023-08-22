#include <iostream>
#include "calc.h"



int main()
{
	setlocale(LC_ALL, "Russian");

	int userNum1 = 0, userNum2 = 0, userAct = 0;

	std::cout << "Введите первое число: ";
	std::cin >> userNum1;

	std::cout << "Введите второе число: ";
	std::cin >> userNum2;

	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> userAct;

	calc(userNum1, userNum2, userAct);

}