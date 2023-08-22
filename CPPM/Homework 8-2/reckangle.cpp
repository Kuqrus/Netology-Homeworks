#include "rectangle.h"

createRectangle::createRectangle(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d) : createQuad(s_a, s_b, s_c, s_d, c_a, c_b, c_c, c_d, "Прямоугольник") {
	if (s_a != s_c || s_b != s_d) {
		throw shapeErrorRect();
	}
	if (c_a != 90 && c_b != 90 && c_c != 90 && c_d != 90) {		
		throw shapeErrorRect();
	}
	
}