#include <iostream>
#include <fstream>

int* createArray_temp(std::ifstream& file, int size) {
	int* array = new int[size];
	for (int x = 0; x < size; x++) {
		file >> array[x];
	}
	return array;
}

//int main_temp() {

	std::ifstream file_in("in.txt");
	if (!file_in.is_open()) {
		std::cout << "Couldn't open file \"in.txt\"!";
		return 0;
	}

	int size1 = 0;
	file_in >> size1;
	int* array1 = createArray(file_in, size1);
	for (int x = 0; x < size1; x++) {
		std::cout << array1[x] << ' ';
	}

	std::cout << std::endl;

	int size2 = 0;
	file_in >> size2;
	int* array2 = createArray(file_in, size2);
	for (int x = 0; x < size2; x++) {
		std::cout << array2[x] << ' ';
	}

	file_in.close();

	std::ofstream file_out("out.txt");
	if (!file_out.is_open()) {
		std::cout << "Couldn't open file \"out.txt\"!";
		return 0;
	}

	file_out << size2 << std::endl;
	for (int x = 0; x < size2; x++) {
		if (x == 0) {
			file_out << array2[size2 - 1];
		}
		else {
			file_out << ' ' << array2[x - 1];
		}
	}

	file_out << std::endl << size1 << std::endl;
	for (int x = 0; x < size1; x++) {
		if (x == size1 - 1) {
			file_out << array1[0];
		}
		else {
			file_out << array1[x + 1] << ' ';
		}
	}

}