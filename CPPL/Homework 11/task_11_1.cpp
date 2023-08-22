#include "task_11_1.h"

template <class T>
void MoveVectors(std::vector<T>& lhs, std::vector<T>& rhs) {
	rhs = std::move(lhs);
}

void task_11_1() {
	std::vector<std::string> one = { "not", "empty", "vector"};
	std::vector<std::string> two;

	MoveVectors(one, two);

	for (const auto& el : two) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}