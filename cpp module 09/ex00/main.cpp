#include "BitcoinExchange.hpp"
#include <iostream>

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "unvalid argument number" << std::endl; 
        return 1;
    }

    BitcoinExchange::CalcValues(av[1]);
    
    return 0;
}