#include <iostream>
#include "counter.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	char isUserValue = ' ';

	std::cout << "Вы хотите задать начальное значение (y/n)? ";
	std::cin >> isUserValue;

	if (isUserValue == 'y') {
		int userValue = 0;
		std::cout << "Введите начальное значение: ";
		std::cin >> userValue;
		counter test(userValue);
		counterAction(test);
	}
	else if (isUserValue == 'n') {
		counter test;
		counterAction(test);
	}

}

