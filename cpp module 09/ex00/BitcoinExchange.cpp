#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cmath>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void) other; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) { (void) other; return (*this); }
BitcoinExchange::~BitcoinExchange(void) {}

static void ft_strtrim(std::string& str, char del) {
    size_t start = str.find_first_not_of(del);

    if (start == std::string::npos) {
        str.clear();
        return;
    }

    size_t end = str.find_last_not_of(del);

    str = str.substr(start, end - start + 1);
}

static void getData(std::map<std::string, std::string>& data) {
    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open())
        throw std::runtime_error("Error: can't open file!\n");

    std::string buffer;
    bool skipHeader = true;
    while (std::getline(dataFile, buffer, '\n'))
    {
        if (skipHeader) {
            skipHeader = false;
            continue;
        }

        std::stringstream ss(buffer);
        std::map<int, std::string> words;

        int countWords = 0;
        std::string word;
        while (std::getline(ss, word, ',')) {
            ft_strtrim(word, ' ');
            if (word.empty()) {
                throw std::runtime_error("Error: unvalid syntax format in csv file\n");
            }
            words[countWords++] = word;
        }

        if (countWords != 2) {
            throw std::runtime_error("Error: Unvalid column number in csv file\n");
        }

        data[words[0]] = words[1];
    }

}

static void isDate(std::string date) {
    std::stringstream ss(date);

    std::string word;
    int year, month, day;
    char dash1,dash2;

    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || !(ss.eof()))
        throw std::runtime_error("Error: Unvalid date syntax in .csv file: " + date + "\n");

    if (year < 1 || month > 12 || month < 1 || day < 1)
        throw std::runtime_error("Error: Unvalid date range in .csv file: " + date + "\n");

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day > daysInMonth[month - 1])
        throw std::runtime_error("Error: Unvalid day in .csv file: " + date + "\n");

}

static void isNumber(std::string val, int flag) {
    errno = 0;
    char *end;
    double value = std::strtod(val.c_str(), &end);

    if (*end != '\0')
        throw std::runtime_error("Error: Unvalid value in .csv file: " + val + "\n");

    if (errno == ERANGE)
        throw std::runtime_error("Error: Unvalid value in .csv file: " + val + "\n");

    if (flag && (value < 0 || value > 1000))
        throw std::runtime_error("Error: Unvalid value (out of range) in .csv file: " + val + "\n");
}

static void checkData(std::map<std::string, std::string> &data)
{
    std::map<std::string, std::string>::iterator it = data.begin();
    std::map<std::string, std::string>::iterator itEnd = data.end();

    while (it != itEnd) {
        isDate(it->first);
        isNumber(it->second, 0);
        it++;
    }
}

void BitcoinExchange::ShowValues(std::string fileName) {
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> data;

    // store data
    try {
        getData(data);
        checkData(data);
    }
    catch (std::exception &err) {
        std::cerr << err.what();
        return ;
    }

    // std::map<std::string, std::string>::iterator it = data.begin();
    // std::map<std::string, std::string>::iterator itEnd = data.end();
    // while (it != itEnd) {
    //     std::cout << it->first << " , " << it->second << std::endl;
    //     it++;
    // }

    (void)fileName;
    // get values
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
        throw std::runtime_error("Error: can't open file!\n");

    std::string buffer;
    bool skipHeader = true;
    while (std::getline(inputFile, buffer, '\n'))
    {
        if (skipHeader) {
            skipHeader = false;
            continue ;
        }

        std::stringstream ss(buffer);
        std::string word;

        while (std::getline(ss, word, '|'))
        {
            ft_strtrim(word, ' ');
        }
    }

}