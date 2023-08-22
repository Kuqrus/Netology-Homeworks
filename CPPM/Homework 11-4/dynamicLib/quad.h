#pragma once
#include <iostream>
#include "shape.h"

class createQuad : public createShape {
public:
    dynamicLib_API createQuad(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d, std::string name_ = "Четырехугольник");

    dynamicLib_API int get_side_a();
    dynamicLib_API int get_side_b();
    dynamicLib_API int get_side_c();
    dynamicLib_API int get_side_d();

    dynamicLib_API int get_corner_a();
    dynamicLib_API int get_corner_b();
    dynamicLib_API int get_corner_c();
    dynamicLib_API int get_corner_d();

    dynamicLib_API void info() override;

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