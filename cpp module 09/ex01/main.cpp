#include "RPN.hpp"

int main(int ac, char **av) {

    try {
        if (ac == 1)
            throw std::runtime_error("Error: Unvalid argument numbers.");
        RPN main;

        main.calculate(av[1]);

    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
