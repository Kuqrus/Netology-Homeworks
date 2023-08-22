#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	double res() {		
		return static_cast<double>(numerator_) / static_cast<double>(denominator_);
	}

	bool operator==(Fraction right) {
		if (numerator_ == right.numerator_) {
			if (denominator_ == right.denominator_) {
				return true;
			}
			else return false;
		}
		else return false;
	}
	bool operator!=(Fraction right) {
		return !(*this == right);
	}

	bool operator>(Fraction right) {
		
		if (res() > right.res()) {
			return true;
		}
		else return false;
	}
	bool operator<(Fraction right) {
		return (right > *this);
	}

	bool operator>=(Fraction right) {
		return !(*this < right);
	}
	bool operator<=(Fraction right) {
		return !(*this > right);
	}
};



int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}