#pragma once
#include <iostream>
#include "quad.h"

class createRhomd : public createQuad {
public:
    dynamicLib_API createRhomd(int s_a, int c_a, int c_d);
};