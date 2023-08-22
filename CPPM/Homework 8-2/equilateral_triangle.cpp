#include "equilateral_triangle.h"

createEquilateralTriangle::createEquilateralTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c) : createTriangle(s_a, s_b, s_c, c_a, c_b, c_c, "Равносторонний треугольник") {
	if (s_a != s_b != s_c) {
		throw shapeErrorNotEqual();
	}
	else if (c_a != 60 && s_b != 60 && s_c != 60) {
		throw shapeErrorNotEqual();
	}
}