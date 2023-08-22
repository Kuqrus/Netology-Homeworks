#pragma once
#include <iostream>
#include "shape.h"

class createTriangle : public createShape {
public:
    dynamicLib_API createTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c, std::string name_ = "Треугольник");

    dynamicLib_API int get_side_a();
    dynamicLib_API int get_side_b();
    dynamicLib_API int get_side_c();

    dynamicLib_API int get_corner_a();
    dynamicLib_API int get_corner_b();
    dynamicLib_API int get_corner_c();

    dynamicLib_API void info() override;

private:
    int side_a;
    int side_b;
    int side_c;

    int corner_a;
    int corner_b;
    int corner_c;
};