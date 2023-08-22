#include "counter.h"

counter::counter() { num = 1; };
counter::counter(int x) { num = x; };

int counter::add() { return num++; };
int counter::sub() { return num--; };
void counter::print() { std::cout << "Текущее значение: " << num << std::endl; };

void counterAction(counter value) {
	char userAction = ' ';
	while (userAction != 'x')
	{
		std::cout << "Выберите действие (+, -, =, x): ";
		std::cin >> userAction;

		switch (userAction)
		{
		case('+'):
			value.add();
			break;
		case('-'):
			value.sub();
			break;
		case('='):
			value.print();
			break;
		default:
			break;
		}

	}
}
