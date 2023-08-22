#pragma once
#include <iostream>
#include "error.h"

class createShape {
public:
    createShape(std::string name_, int side_);    
    std::string getName();

    virtual void info();

private:
    std::string name;
    int side;
};