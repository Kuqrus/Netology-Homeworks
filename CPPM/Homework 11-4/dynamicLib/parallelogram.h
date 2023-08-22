#pragma once
#include <iostream>
#include "quad.h"

class createParallelogram : public createQuad {
public:
    dynamicLib_API createParallelogram(int s_a, int s_d, int c_a, int c_d);
};