#pragma once
#include <iostream>

class counter
{
public:

	counter();
	counter(int num_);

	int add();
	int sub();
	void print();

private:
	int num;
};

void counterAction(counter);