#include <iostream>
#include <matrix.hpp>
#include <fstream>

int main()
{
    std::ifstream f {"matrix.txt"};
    if (auto om = Matrix<double, 3, 3>::import(f);
        om) {
        std::cout << *om << '\n';
        std::ofstream dumpfile {"dump.txt"};
        if (om->exporrt(dumpfile)) {
            std::cout << "yes, export hat geklappt\n";
        }
    } else {
        std::cout << "das hat nicht geklappt.\n";
    }

}