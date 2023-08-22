#pragma once
#include <iostream>
#include "quad.h"

class createParallelogram : public createQuad {
public:
    createParallelogram(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d);
};