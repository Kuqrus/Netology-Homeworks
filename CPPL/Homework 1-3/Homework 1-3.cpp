#include <iostream>
#include <vector>
#include <functional>

int main()
{
	setlocale(LC_ALL, "rus");

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
}