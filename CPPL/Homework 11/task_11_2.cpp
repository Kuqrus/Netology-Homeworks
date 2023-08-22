#include "task_11_2.h"

BigInteger::BigInteger(std::string _int) : integer{ _int } {}
BigInteger::BigInteger(const BigInteger& obj) : integer{ obj.integer } {}
BigInteger::BigInteger(BigInteger&& obj) noexcept : BigInteger(std::exchange(obj.integer, nullptr)) {}

BigInteger BigInteger::operator=(const BigInteger& left) {
	if (this != &left) {
		integer = left.integer;
	}
	return *this;
}
BigInteger BigInteger::operator=(BigInteger&& left) noexcept {
	std::swap(integer, left.integer);
	return *this;
}

BigInteger BigInteger::operator+(BigInteger& left) {
	if (integer.length() != left.integer.length()) {
		if (integer.length() > left.integer.length()) {
			while (integer.length() != left.integer.length()) {
				left.integer = "0" + left.integer;
			}
		}
		else if (integer.length() < left.integer.length()) {
			while (integer.length() != left.integer.length()) {
				integer = "0" + integer;
			}
		}
	}

	std::vector<int> resultAsVector(integer.length());
	for (int i = static_cast<int>(integer.length()) - 1; i >= 0; i--) {
		int num1 = integer[i] - '0', num2 = left.integer[i] - '0';
		resultAsVector[i] += num1 + num2;
		if (resultAsVector[i] > 9 && i != 0) {
			resultAsVector[i] -= 10;
			resultAsVector[i - 1] += 1;
		
		}
	}

	std::string result;
	for (const auto& el : resultAsVector) {
		result += std::to_string(el);
	}
	return result;
}

BigInteger BigInteger::operator*(int mult) {
	std::vector<int> resultAsVector(integer.length());
	for (int i = static_cast<int>(integer.length()) - 1; i >= 0; i--) {
		int num1 = integer[i] - '0';
		resultAsVector[i] += num1 * mult;
		if (resultAsVector[i] > 9 && i != 0) {
			int dozen = resultAsVector[i] - (resultAsVector[i] % 10);
			resultAsVector[i] -= dozen;
			resultAsVector[i - 1] += dozen / 10;

		}
	}
	std::string result;
	for (const auto& el : resultAsVector) {
		result += std::to_string(el);
	}
	return result;
}

std::ostream& operator<<(std::ostream& stream, const BigInteger& obj) {
	stream << obj.GetResult();
	return stream;
}

std::string BigInteger::GetResult() const { return integer; }

BigInteger::~BigInteger() {}

void task_11_2() {

	auto num1 = BigInteger("12345");
	BigInteger num2(BigInteger("6789"));

	auto num3 = num1 + num2;
	std::cout << "num1(" << num1 << ") + num2(" << num2 << ") = num3(" << num3<< ")" << std::endl;

	auto num4 = num1 * 5;
	std::cout << "num1(" << num1 << ") * 5 = num4(" << num4 << ")" << std::endl;


	
}