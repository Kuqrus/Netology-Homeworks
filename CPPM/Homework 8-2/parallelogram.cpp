#include "parallelogram.h"

createParallelogram::createParallelogram(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d) : createQuad(s_a, s_b, s_c, s_d, c_a, c_b, c_c, c_d, "ֿאנאככוכמדנאלל") {
	if (!(s_a == s_c && s_b == s_d)) {
		throw shapeErrorParall();
	}
	else if (!(c_a == c_c && c_b == c_d)) {
		throw shapeErrorParall();
	}
}