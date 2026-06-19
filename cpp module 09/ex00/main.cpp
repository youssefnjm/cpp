#include "BitcoinExchange.hpp"
#include <stdexcept>

int main (int ac, char **av)
{
    try {

        if (ac != 2)
            throw std::runtime_error("Error: unvalid argument number");

        BitcoinExchange::ShowValues(av[1]);
    
    } catch (std::exception &exp) {
        std::cerr << exp.what() << std::endl;
        return 1; 
    }
    
    return 0;
}