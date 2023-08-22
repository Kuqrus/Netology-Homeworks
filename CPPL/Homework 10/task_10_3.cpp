#include "task_10_3.h"

void task_10_3() {
	uniqe<int> ptr_test(new int(10));
	std::cout << *ptr_test << std::endl;
	std::cout << ptr_test.ptr << std::endl;
	std::cout << ptr_test.Release() << std::endl;
}