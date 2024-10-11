#include <cstddef>
#include <array>
#include <iostream>
#include <initializer_list>

template <typename T, size_t ROWS, size_t COLS>
class Matrix {
    std::array<T, ROWS * COLS> v;

public:
    Matrix() = default;
    Matrix(std::initializer_list<T> il) 
    {
        std::copy(il.begin(), il.end(), v.begin());
    }

    const T& operator()(size_t row, size_t col) const {
        return v[row * COLS + col];
    }
    
    T& operator()(size_t row, size_t col) {
        return const_cast<T&>(const_cast<const Matrix&>(*this)(row, col));
    }
};

template <typename T, size_t Rows, size_t Cols>
std::ostream& operator<<(std::ostream& os, const Matrix<T, Rows, Cols> &m) {
    os << "{\n";
    for (size_t row {0}; row < Rows; ++row) {
        os << " { ";
        for (size_t col {0}; col < Cols; ++col) {
            os << m(row, col) << ", ";
        }
        os << "}\n";
    }
    os << "}\n";
    return os;
}