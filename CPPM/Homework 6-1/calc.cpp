#include "calc.h"

void calc(int x, int y, int act) {
	switch (act)
	{
	case(1):
		std::cout << x << " + " << y << " = " << x + y << std::endl;
		break;
	case(2):
		std::cout << x << " - " << y << " = " << x - y << std::endl;
		break;
	case(3):
		std::cout << x << " * " << y << " = " << x * y << std::endl;
		break;
	case(4):
		std::cout << x << " / " << y << " = " << x / y << std::endl;
		break;
	case(5):
		std::cout << x << " в степени " << y << " = " << std::pow(x, y) << std::endl;
		break;
	default:
		break;
	}
}