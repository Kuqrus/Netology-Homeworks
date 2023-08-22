#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>
#include <cmath>
#include <functional>

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
    setlocale(LC_ALL, "rus");

    // 1-1
	
    //std::vector<int> v = { 4, 7, 9, 14, 12 };
    //std::cout << "Входные данные: " << std::endl;
    //std::for_each(v.begin(), v.end(), [](int i) {std::cout << i << " "; });
    //std::cout << std::endl;
    //auto func_ = [&v](int& i) {
    //    if (i % 2 != 0) {
    //        i *= 3;
    //    }        
    //};
    //std::for_each(v.begin(), v.end(), func_);
    //std::cout << "Выходные данные: " << std::endl;
    //std::for_each(v.begin(), v.end(), [](int i) {std::cout << i << " "; });

    // 1-2
	
	//std::variant<int, std::string, std::vector<int>> some;
	//some = get_variant();
	//if (std::holds_alternative<int>(some)) {
	//	int x = std::get<int>(some) * 2;
	//	std::cout << x;
	//}
	//else if (std::holds_alternative<std::string>(some)) {
	//	std::string x = std::get<std::string>(some);
	//	std::cout << x;
	//}
	//else if (std::holds_alternative<std::vector<int>>(some)) {
	//	std::vector<int> x = std::get<std::vector<int>>(some);
	//	for (int i : x) {
	//		std::cout << i << " ";
	//	}
	//}


	// 1-3

	double pi = 3.1415926;
	std::vector<int>angle{ 30, 60, 90 };
	std::vector<double>radian;

	std::cout << "Входные данные: " << std::endl;
	for (auto& i : angle) {
		std::cout << i << " * " << pi << " / " << 180 << std::endl;
		radian.push_back(static_cast<double>(i) * pi / 180);
	}

	std::vector<std::function<void(double angle)>> func;

	func.emplace_back([pi](double rad) {
		double angle = rad * 180 / pi;
		std::cout << "sin: " << sin(angle * pi / 180) << " ";
		});

	func.emplace_back([pi](double rad) {
		double angle = rad * 180 / pi;
		std::cout << "cos: " << cos(angle * pi / 180) << " ";
		});

	func.emplace_back([pi](double rad) {
		double angle = rad * 180 / pi;
		std::cout << "tan: " << tan(angle * pi / 180) << " ";
		});

	std::cout << "Выходные данные: " << std::endl;
	for (const auto& angle : radian) {
		std::cout << angle << ": ";
		for (const auto& function : func)
			function(angle);
		std::cout << std::endl;
	}


	//std::cout << sin(30*pi/180);
}