#include <iostream>

enum months {
	jan = 1, feb, mar, apr,	may, jun, jul, avg, sep, oct, nov, dec
};

int main() {
	
	setlocale(LC_ALL, "Russian");
	int x = 0;

	while (true) {		

		std::cout << "������� ����� ������: ";
		std::cin >> x;
		
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "���������� ������ �����!" << std::endl;
			continue;
		}
		if (x == 0) {
			break;
		}
		if (x < 0 || x > 12) {
			std::cout << "����� ������ ���� �� 1 �� 12!" << std::endl;
			continue;
		}

		switch (static_cast<months>(x))
		{
		case months::jan:
			std::cout << "������";
			break;
		case months::feb:
			std::cout << "�������";
			break;
		case months::mar:
			std::cout << "����";
			break;
		case months::apr:
			std::cout << "������";
			break;
		case months::may:
			std::cout << "���";
			break;
		case months::jun:
			std::cout << "����";
			break;
		case months::jul:
			std::cout << "����";
			break;
		case months::avg:
			std::cout << "������";
			break;
		case months::sep:
			std::cout << "��������";
			break;
		case months::oct:
			std::cout << "�������";
			break;
		case months::nov:
			std::cout << "������";
			break;
		case months::dec:
			std::cout << "�������";
			break;
		default:
			break;
		}
		
		std::cout << std::endl;

	}
}