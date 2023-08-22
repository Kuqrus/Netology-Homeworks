#pragma once
#include <iostream>

template <class T>
class uniqe {

public:
	T* ptr;
	uniqe(T* _ptr) {
		ptr = _ptr;
	}

	uniqe(const uniqe& obj) = delete;
	uniqe& operator=(const uniqe& obj) = delete;

	T& operator*() {
		return *ptr;
	}

	T* Release() {
		delete ptr;
		ptr = nullptr;
		return ptr;
	}	

	~uniqe() { delete ptr; };
};

void task_10_3();
