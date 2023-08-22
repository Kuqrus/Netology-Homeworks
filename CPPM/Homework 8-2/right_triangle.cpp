#include "right_triangle.h"

createRightTriangle::createRightTriangle(int s_a, int s_b, int s_c, int c_a, int c_b, int c_c) : createTriangle(s_a, s_b, s_c, c_a, c_b, c_c, "Прямоугольный треугольник") {
	
	if (c_c != 90) {
		throw shapeError90();
	}
	
	
}