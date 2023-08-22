#pragma once
#include <iostream>

template<class T>
class table
{
private:
	class subTable;
	subTable* arr;
	int row = 0;
	int col = 0;
	class subTable {
	public:
		T* subArr;
		subTable() {};
		subTable(int size) {
			subArr = new T[size];
		}
		T& operator[](int i) {
			return subArr[i];
		}

		const T& operator[](int i) const {
			return subArr[i];
		}
	};

public:
	table(int _row, int _col) {
		arr = new subTable[_row];
		for (int i = 0; i < _row; i++) {
			arr[i] = subTable(_col);
		}
		row = _row;
		col = _col;
	};

	table(const table& _table) {
		row = _table.row;
		col = _table.col;

		arr = new subTable[row];
		for (int i = 0; i < row; i++) {
			arr[i] = subTable(col);
			for (int j = 0; j < col; j++) {
				arr[i][j] = _table.arr[i][j];
			}
		}
	};

	subTable& operator[](int j) {
		return arr[j];
	}

	const subTable& operator[](int j) const {
		return arr[j];
	}

	table& operator=(const table& left) {
		for (int i = 0; i < row; i++) {
			delete[](arr[i].subArr);
		}
		delete[] arr;
		
		row = left.row;
		col = left.col;

		arr = new subTable[row];
		for (int i = 0; i < row; i++) {
			arr[i] = subTable(col);
			for (int j = 0; j < col; j++) {
				arr[i][j] = left.arr[i][j];
			}
		}
		return *this;
	}

	const int Size() const {
		return col * row;
	}

	~table() {
		for (int i = 0; i < row; i++) {
			delete[](arr[i].subArr);
		}
		delete[] arr;
	}
};

void task_5_2() {
	table<int> x(2, 2);
	x[0][0] = 55;
	x[0][1] = 33;
	std::cout << x[0][0] << " " << x[0][1] << std::endl;

	table<int> y(1, 1);
	y = x;
	std::cout << x[0][0] << " " << x[0][1] << std::endl;

	table<int> z(x);
	std::cout << z[0][0] << " " << z[0][1] << std::endl;
}
