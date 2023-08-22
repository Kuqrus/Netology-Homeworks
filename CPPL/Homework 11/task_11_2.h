#pragma once
#include <iostream>
#include <string>
#include <vector>

class BigInteger {
private:
	std::string integer;
public:
	BigInteger(std::string _int);
	BigInteger(const BigInteger& obj);
	BigInteger(BigInteger&& obj) noexcept;

	BigInteger operator=(const BigInteger& left);
	BigInteger operator=(BigInteger&& left) noexcept;

	BigInteger operator+(BigInteger& left);
	BigInteger operator*(int mult);

	std::string GetResult() const;

	~BigInteger();
};

std::ostream& operator<<(std::ostream& stream, const BigInteger& obj);

void task_11_2();
