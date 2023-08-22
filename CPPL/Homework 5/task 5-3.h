#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class functor {
private:
	int sum, count;

public:
	functor();
	void operator()(int num);

	int getSum();
	int getCount();
};

void task_5_3();