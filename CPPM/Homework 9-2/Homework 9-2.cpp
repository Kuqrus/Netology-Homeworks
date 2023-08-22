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

	void print() {
		std::cout << numerator_ << "/" << denominator_;
	}

	Fraction operator+(Fraction r) {
		return Fraction((numerator_ * r.denominator_) + (r.numerator_ * denominator_), (denominator_ * r.denominator_));
	}
	Fraction operator-(Fraction r) {
		return Fraction((numerator_ * r.denominator_) - (r.numerator_ * denominator_), (denominator_ * r.denominator_));
	}

	Fraction operator*(Fraction r) {
		int x = 0, y = 0;

		if (r.numerator_ % denominator_ == 0) {
			x = numerator_ * (r.numerator_ / denominator_);
		}
		else if (numerator_ % r.denominator_ == 0) {
			x = (numerator_ / r.denominator_) * numerator_;
		}
		else x = numerator_ * r.numerator_;

		if (denominator_ % r.numerator_ == 0) {
			y = r.denominator_ * (denominator_ / r.numerator_);
		}
		else if (r.denominator_ % numerator_ == 0) {
			y = denominator_ * (r.denominator_ / numerator_);
		}
		else y = denominator_ * r.denominator_;

		return Fraction(x, y);
	}
	Fraction operator/(Fraction r) {
		int x = 0, y = 0;
		
		if (denominator_ % r.denominator_ == 0) {
			x = r.numerator_ * (denominator_ / r.denominator_);
		}
		else if (r.denominator_ % denominator_ == 0) {
			x = numerator_ * (r.denominator_ / denominator_);
		}
		else x = numerator_ * r.denominator_;

		if (r.numerator_ % numerator_ == 0) {
			y = denominator_ * (r.numerator_ / numerator_);
		}
		else if (numerator_ % r.numerator_ == 0) {
			y = (numerator_ / r.numerator_) * denominator_;
		}
		else y = r.numerator_ * denominator_;

		return Fraction(x, y);

	}

	Fraction operator++() {
		numerator_ += denominator_;
		return Fraction(*this);
	}
	Fraction operator++(int) {
		Fraction tmp = *this;
		++(*this);
		return tmp;		
	}

	Fraction operator--() {
		numerator_ -= denominator_;
		return Fraction(*this);
	}
	Fraction operator--(int) {
		Fraction tmp = *this;
		--(*this);
		return tmp;
	}

};

void line(Fraction f1, Fraction f2, Fraction f3, char sym) {
	f1.print();
	std::cout << " " << sym << " ";
	f2.print();
	std::cout << " = ";
	f3.print();
	std::cout << std::endl;
}

int main()
{
	Fraction f1(3, 4);
	Fraction f2(4, 5);	

	Fraction f3 = f1 + f2;
	line(f1, f2, f3, '+');

	f3 = f1 - f2;
	line(f1, f2, f3, '-');

	f3 = f1 * f2;
	line(f1, f2, f3, '*');

	f3 = f1 / f2;
	line(f1, f2, f3, '/');

	std::cout << std::endl;

	std::cout << "f1 = ";
	f1.print();

	Fraction f1pp = f1++;
	Fraction ppf1 = ++f1;
	
	std::cout << ", if f1++ = ";
	f1pp.print();
	std::cout << ", if ++f1 = ";
	ppf1.print();
	
	std::cout << std::endl << std::endl;

	std::cout << "f2 = ";
	f2.print();

	Fraction f2mm = f2--;
	Fraction mmf2 = --f2;	

	std::cout << ", if f2-- = ";
	f2mm.print();
	std::cout << ", if --f2 = ";
	mmf2.print();
	


	return 0;
}