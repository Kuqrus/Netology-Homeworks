#include "isosceles_triangle.h"

createIsoscelesTriangle::createIsoscelesTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c) : createTriangle(s_a, s_b, s_c, c_a, c_b, c_c, "Равнобедренный треугольник") {
	if (c_a != c_c) {
		throw shapeErrorNotIsosceles();
	}
	else if (s_a != s_c) {
		throw shapeErrorNotIsosceles();
	}
}