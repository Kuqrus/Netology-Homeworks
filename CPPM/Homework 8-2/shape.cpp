#include "shape.h"

createShape::createShape(std::string name_ = "Фигура", int side_ = 0) {
    name = name_;
    side = side_;
}

std::string createShape::getName() { return name; }

void createShape::info() { std::cout << name << ": " << std::endl; }
