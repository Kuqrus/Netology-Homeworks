#include "task_10_1.h"


tridiagonal_matrix::tridiagonal_matrix(
    const std::vector<double>& down,
    const std::vector<double>& upper,
    const std::vector<double>& middle) :
    m_down{ down }, m_upper{ upper }, m_middle{ middle } {};

tridiagonal_matrix::~tridiagonal_matrix() { std::cout << "destructor called\n"; }

auto tridiagonal_matrix::clone() {
    auto ptr = std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    return ptr;
}

void task_10_1()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
        );

    auto matrix_clone = matrix->clone();
}