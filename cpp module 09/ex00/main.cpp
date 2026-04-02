#include "BitcoinExchange.hpp"
#include <iostream>

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: unvalid argument number" << std::endl;
        return 1;
    }

    BitcoinExchange::ShowValues(av[1]);
    
    return 0;
}