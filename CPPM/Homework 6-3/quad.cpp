#include "quad.h"

createQuad::createQuad(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d, std::string name_) : createShape(name_, 4) {
    side_a = s_a;
    side_b = s_b;
    side_c = s_c;
    side_d = s_d;

    corner_a = c_a;
    corner_b = c_b;
    corner_c = c_c;
    corner_d = c_d;
}

int createQuad::get_side_a() { return side_a; }
int createQuad::get_side_b() { return side_b; }
int createQuad::get_side_c() { return side_c; }
int createQuad::get_side_d() { return side_d; }

int createQuad::get_corner_a() { return corner_a; }
int createQuad::get_corner_b() { return corner_b; }
int createQuad::get_corner_c() { return corner_c; }
int createQuad::get_corner_d() { return corner_d; }

void createQuad::info() {
    createShape::info();
    std::cout << "Стороны: a = " << get_side_a() << ", b = " << get_side_b() << ", c = " << get_side_c() << ", d = " << get_side_d() << std::endl;
    std::cout << "Углы: A = " << get_corner_a() << ", B = " << get_corner_b() << ", C = " << get_corner_c() << ", D = " << get_corner_d() << std::endl;
    std::cout << std::endl;
}