#include <iostream>

class shape {
public:
    shape (std::string name_ = "Фигура", int side_ = 0) {
        name = name_;
        side = side_;
    }
    void printAtributs() { std::cout << name << ": " << side << std::endl; }

private:
    std::string name;
    int side;
};

class triangle : public shape{
public:
    triangle() : shape("Тругольник", 3) {}
};

class quad : public shape {
public:
    quad() : shape("Четырёхугольник", 4) {}
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Количество сторон:" << std::endl;

    shape test_shape;
    test_shape.printAtributs();

    triangle test_triangle;
    test_triangle.printAtributs();

    quad test_quad;
    test_quad.printAtributs();

}
