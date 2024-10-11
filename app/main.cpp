#include <iostream>
#include <matrix.hpp>
#include <fstream>
#include <sstream>

int main()
{
    //std::ifstream f {"matrix.txt"};
    std::istringstream is {"1 2 3 4 5 6 7 8 9"};
    if (auto om = Matrix<double, 3, 3>::import(is);
        om) {
        std::cout << *om << '\n';
        std::ofstream dumpfile {"dump.txt"};
        std::ostringstream os;
        if (om->exporrt(os)) {
            std::cout << "yes, export hat geklappt\n";
            std::cout << os.str() << '\n';
        }
    } else {
        std::cout << "das hat nicht geklappt.\n";
    }

}