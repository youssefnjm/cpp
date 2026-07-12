#include "RPN.hpp"
#include <iomanip>

int main(int ac, char **av) {

    try {
        if (ac != 2)
            throw std::runtime_error("Error: Unvalid argument numbers.");
        RPN main;
        std::cout << std::setprecision(10);
        main.calculate(av[1]);

    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
