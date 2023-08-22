#pragma once
#include <iostream>

class smart_array {

private:
	int size = 0;
	int counter = 0;
	int* arr;

public:
	smart_array(int size_);
	smart_array(const smart_array& _arr);

	void add_element(int el);
	int get_element(int el);

	void get_info();

	smart_array operator+(smart_array& left);

	smart_array operator=(const smart_array& left);
	

	~smart_array();
};