#include "rhomb.h"

createRhomd::createRhomd(int s_a, int s_b, int s_c, int s_d, int c_a, int c_b, int c_c, int c_d) : createQuad(s_a, s_b, s_c, s_d, c_a, c_b, c_c, c_d, "Ромб") {
	if (!(s_a = s_b && s_b == s_c && s_c == s_d)) {
		throw shapeErrorRhomb();
	}
	else if (!(c_a == c_c && c_b == c_d)) {
		throw shapeErrorRhomb();
	}
}