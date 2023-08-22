#include "task 5-3.h"

functor::functor() {
	sum = 0;
	count = 0;
}
void functor::operator()(int num) {
	if (num % 3 == 0 && num != 0) {
		count++;
		sum += num;
	}
}

int functor::getSum() {
	return sum;
}

int functor::getCount() {
	return count;
}



void task_5_3() {
	std::vector<int> arrFunc(10);
	std::for_each(arrFunc.begin(), arrFunc.end(), [&arrFunc](int& el) {
		el = std::rand() % 50;
		});
	for (const auto& i : arrFunc) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	functor f;
	f = for_each(arrFunc.begin(), arrFunc.end(), f);
	std::cout << "Get sum: " << f.getSum() << std::endl;
	std::cout << "Get count: " << f.getCount() << std::endl;
}