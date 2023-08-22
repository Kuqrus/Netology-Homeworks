#pragma once
#include <iostream>

class createShape {
public:
    createShape(std::string name_, int side_);
    std::string getName();

    virtual void info();

private:
    std::string name;
    int side;
};