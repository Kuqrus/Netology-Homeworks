#pragma once
#include <iostream>

template<class T>
class vectoriya {
private:
    T* arr;
    int size = 0, capacity = 0;
public:
    vectoriya() {}
    vectoriya(int _cap) {
        capacity = _cap;
        arr = new T[capacity];
    }
    vectoriya(const vectoriya& left) {
        size = left.size;
        capacity = left.capacity;
        arr = new T[capacity];

        for (int i = 0; i < size; i++) {
            arr[i] = left.arr[i];
        }
    }

    void Push_back(T value) {

        if (capacity == 0) {
            capacity = 1;
            arr = new T[capacity];
        }

        if (size >= capacity) {
            T* tempArr = new T[capacity];
            for (int i = 0; i < size; i++) {
                tempArr[i] = arr[i];
            }
            delete[] arr;

            double newCapacity = capacity * 1.5;
            capacity = static_cast<int>(newCapacity);

            arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = tempArr[i];
            }
            delete[] tempArr;

        }
        arr[size] = value;
        size++;
    }

    T At(int index) {
        if (index < 0 || index >= size) {
            throw std::exception{ "Wrong index!" };
        }
        return arr[index];
    }

    int Size() {
        return size;
    }
    int Capacity() {
        return capacity - size;
    }

    vectoriya operator=(const vectoriya& left) {
        if (arr != left.arr) {
            if (capacity < left.capacity) {
                delete[] arr;
                arr = new T[left.capacity];
            }
            size = left.size;
            capacity = left.capacity;

            for (int i = 0; i < size; i++) {
                arr[i] = left.arr[i];
            }
        }
        return *this;
    }

    ~vectoriya() {
        delete[] arr;
    }
};

void task_7_3();
