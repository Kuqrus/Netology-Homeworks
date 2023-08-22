#pragma once
#include <iostream>
#include "shape.h"

class createTriangle : public createShape {
public:
    createTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c, std::string name_ = "Треугольник");

    int get_side_a();
    int get_side_b();
    int get_side_c();

    int get_corner_a();
    int get_corner_b();
    int get_corner_c();

    void info() override;

private:
    int side_a;
    int side_b;
    int side_c;

    int corner_a;
    int corner_b;
    int corner_c;
};