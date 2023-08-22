#include "smart_array.h"

smart_array::smart_array(int size_) {
	size = size_;
	arr = new int[size];
}

smart_array::smart_array(const smart_array& _arr) {
	size = _arr.size;
	counter = _arr.counter;

	// Добавил эту строчку так как без нее в 17 строке вылезает предупреждение C6386
	if (counter > size) throw std::exception{ "Cannot create array, counter exceecds size!" };

	arr = new int[size];
	for (int i = 0; i < counter; i++) {		
		arr[i] = _arr.arr[i];
	}
}


void smart_array::add_element(int el) {
	if (counter >= size) {
		throw std::exception{ "Cannot add more elements!" };
	}
	arr[counter++] = el;
}

int smart_array::get_element(int el) {
	if (el >= size) {
		throw std::exception{ "Wrong index!" };
	}
	return arr[el];
}

void smart_array::get_info() {
	std::cout << "Size: " << size << std::endl;
	std::cout << "Counter: " << counter << std::endl;
	std::cout << "Elements: ";
	if (counter == 0) {
		std::cout << "none" << std::endl;
		return;
	}
	for (int i = 0; i < counter; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

smart_array smart_array:: operator+(smart_array& left) {
	if (size == counter) {
		throw std::exception{ "Array is full!" };
	}
	else if (counter + left.counter > size) {
		throw std::exception{ "Array is not big enough!" };
	}
	int rightIndex = counter;
	for (int i = 0; i < size - counter; i++) {
		arr[rightIndex++] = left.arr[i];
	}
	counter = rightIndex;
	return *arr;
}

smart_array smart_array:: operator=(const smart_array& left) {
	if (this != &left) {
		if (left.counter > size) {
			delete[] arr;
			arr = new int[left.size];
		}

		size = left.size;
		counter = left.counter;		

		if (counter > size) throw std::exception{ "Cannot create array, counter exceecds size!" };

		for (int i = 0; i < counter; i++) {
			arr[i] = left.arr[i];
		}
	}
	return *this;
}

smart_array::~smart_array() {
	delete[] arr;
}
