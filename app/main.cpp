#include <iostream>
#include <matrix.hpp>

int main()
{
    Matrix<double, 3, 3> m {1,2,3,4,5,6,7,8,9};
    std::cout << m << '\n';
}