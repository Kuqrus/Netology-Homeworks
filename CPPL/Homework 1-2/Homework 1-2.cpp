#include <iostream>
#include<vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	std::variant<int, std::string, std::vector<int>> some;
	some = get_variant();
	if (std::holds_alternative<int>(some)) {
		int x = std::get<int>(some) * 2;
		std::cout << x;
	}
	else if (std::holds_alternative<std::string>(some)) {
		std::string x = std::get<std::string>(some);
		std::cout << x;
	}
	else if (std::holds_alternative<std::vector<int>>(some)) {
		std::vector<int> x = std::get<std::vector<int>>(some);
		for (int i : x) {
			std::cout << i << " ";
		}
	}
}