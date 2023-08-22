#include <iostream>

void print_arr(int* arr, int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//0 root 1      0
//1 left(1) 3   1
//1 right(1) 6  2
//2 left(3) 5   3
//2 right(3) 9  4
//2 left(6) 8   5

void print_pyramid(int* arr, int size) {
    int layer = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            std::cout << layer << " root ";
            ++layer;
        }
        else if (i % 2 != 0) {
            std::cout << layer << " left(" << arr[i - layer] << ") ";
        }
        else if (i % 2 == 0) {
            std::cout << layer << " right(" << arr[i - layer - 1] << ") ";
            ++layer;
        }
        std::cout << arr[i] << "\t" << i << std::endl;
    }
}

class tree_element {
public:
    int m_data;
    tree_element* m_left;
    tree_element* m_right;
    tree_element(int value)
    {
        m_left = nullptr;
        m_right = nullptr;
        m_data = value;
    }
};

class binary_tree {
public:
    binary_tree(int num) {
        m_root = new tree_element(num);
        m_size = 1;
    }
    void print() {
        print_tree(m_root);
        std::cout << std::endl;
    }
    bool find(int num) {
        tree_element* current = m_root;
        while (current && current->m_data != num) {
            if (current->m_data > num) {
                current = current->m_left;
            }
            else current = current->m_right;
        }
        return current != nullptr;
    }
    void add(int num) {
        tree_element* current = m_root;
        while (current && current->m_data != num) {
            if (current->m_data > num && current->m_left == nullptr) {
                current->m_left = new tree_element(num);
                ++m_size;
                return;
            }
            if (current->m_data < num && current->m_right == nullptr) {
                current->m_right = new tree_element(num);
                ++m_size;
                return;
            }
            if (current->m_data > num) {
                current = current->m_left;
            }
            else current = current->m_right;
        }
    }
private:
    tree_element* m_root;
    int m_size;
    void print_tree(tree_element* current) {
        if (current) {
            print_tree(current->m_left);
            std::cout << current->m_data << " ";
            print_tree(current->m_right);
        }
    }
};

int main()
{
    int size = 6;
    int* arr = new int[size] {1, 3, 6, 5, 9, 8};

    print_arr(arr, size);

    print_pyramid(arr, size);

    //binary_tree test(arr[0]);
    //for (int i = 0; i < size; i++) {
    //    test.add(arr[i]);
    //}
    //
    //test.print();
    //
    //test.add(2);
}