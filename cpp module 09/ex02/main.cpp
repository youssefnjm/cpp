#include "PmergeMe.hpp"

int main(int ac, char **av) {

    try {
        if (ac == 1)
            throw std::runtime_error("Error: Unvalid argument numbers.");

        PmergeMe::run(ac, av);

    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
