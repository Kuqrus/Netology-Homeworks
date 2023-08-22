#pragma once
#include <iostream>
#include "shape.h"

class createQuad : public createShape {
public:
    createQuad(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d, std::string name_ = "Четырехугольник");

    int get_side_a();
    int get_side_b();
    int get_side_c();
    int get_side_d();

    int get_corner_a();
    int get_corner_b();
    int get_corner_c();
    int get_corner_d();

    void info() override;

private:
    int side_a;
    int side_b;
    int side_c;
    int side_d;

    int corner_a;
    int corner_b;
    int corner_c;
    int corner_d;
};