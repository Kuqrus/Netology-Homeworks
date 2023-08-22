#include <iostream>

class counter
{
public:

	counter() {
		num = 1;
	}

	counter(int num_) {
		num = num_;
	}

	void setUserValue(int num_) {
		num = num_;
	}
	void setDefaultValue() {
		num = 1;
	}

	int add() { return num++; }
	int sub() { return num--; }
	void print() { std::cout << "Current value: " << num << std::endl; }

private:
	int num;
};

void counterAction(counter value) {
	char userAction = ' ';
	while (userAction != 'x')
	{
		std::cout << "Choose action (+, -, =, x): ";
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

int main()
{
	char isUserValue = ' ';
	
	std::cout << "Do you want to input start value (y/n)? ";
	std::cin >> isUserValue;
	
	if (isUserValue == 'y') {
		int userValue = 0;
		std::cout << "Enter start value: ";
		std::cin >> userValue;
		counter test(userValue);
		counterAction(test);
	}
	else if (isUserValue == 'n') {
		counter test;
		counterAction(test);
	}

}

