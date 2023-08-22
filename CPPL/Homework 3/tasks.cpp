#include "tasks.h"

void task_3_1() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

void task_3_2() {
	try
	{
		smart_array arr(2);
		for (int i = 0; i < 2; i++) {
			arr.add_element(std::rand() % 20);
		}

		const smart_array const_arr_copy(arr);
		smart_array arr_copy(const_arr_copy);

		smart_array new_array(4);
		for (int i = 0; i < 4; i++) {
			new_array.add_element(std::rand() % 20);
		}

		arr = new_array;

		std::cout << "Equalized array:\n";
		arr.get_info();

		std::cout << std::endl;

		std::cout << "Copied const array:\n";
		arr_copy.get_info();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}