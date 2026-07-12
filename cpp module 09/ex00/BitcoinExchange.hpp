#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>

class BitcoinExchange
{
    private:
        void ft_strtrim(std::string& str, char del);
        void isDate(std::string& date);
        void isNumber(std::string& val, int flag);
        double getValue(std::map<time_t, double>& dataBase, std::string &date);
        std::map<time_t, double> getData();
        time_t DateToTimeT(std::string Sdate);

    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        void ShowValues(std::string input);
};

#endif

