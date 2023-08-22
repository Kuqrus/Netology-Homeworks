#include "triangle.h"

createTriangle::createTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c, std::string name_) : createShape(name_, 3) {
    side_a = s_a;
    side_b = s_b;
    side_c = s_c;

    corner_a = c_a;
    corner_b = c_b;
    corner_c = c_c;
}

int createTriangle::get_side_a() { return side_a; }
int createTriangle::get_side_b() { return side_b; }
int createTriangle::get_side_c() { return side_c; }

int createTriangle::get_corner_a() { return corner_a; }
int createTriangle::get_corner_b() { return corner_b; }
int createTriangle::get_corner_c() { return corner_c; }

void createTriangle::info() {
    createShape::info();
    std::cout << "Стороны: a = " << get_side_a() << ", b = " << get_side_b() << ", c = " << get_side_c() << std::endl;
    std::cout << "Углы: A = " << get_corner_a() << ", B = " << get_corner_b() << ", C = " << get_corner_c() << std::endl;
    std::cout << std::endl;
}