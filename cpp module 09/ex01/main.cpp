#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac == 1) {
        std::cerr << "Error\n";
        return 1;
    }

    RPN::calculate(av[1]);

    return 0;
}
