#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        static void CalcValues(std::string input);
};

#endif

