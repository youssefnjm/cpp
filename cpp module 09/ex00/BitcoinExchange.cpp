#include "BitcoinExchange.hpp"
#include <cerrno>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void) other; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) { (void) other; return (*this); }
BitcoinExchange::~BitcoinExchange(void) {}

static void ft_strtrim(std::string& str, char del) {
    size_t start = str.find_first_not_of(del);

    if (start == std::string::npos) {
        str.clear();
        return ;
    }

    size_t end = str.find_last_not_of(del);

    str = str.substr(start, end - start + 1);
}

static void getData(std::map<std::string, std::string>& data) {
    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open())
        throw std::runtime_error("can't open file!");

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
                throw std::runtime_error("unvalid syntax format in csv file");
            }
            words[countWords++] = word;
        }

        if (countWords != 2) {
            throw std::runtime_error("Unvalid column number in csv file");
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
        throw std::runtime_error("Unvalid date syntax YYYY-MM-DD: " + date);

    if (year < 1 || month > 12 || month < 1 || day < 1)
        throw std::runtime_error("Unvalid date range : " + date);

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day > daysInMonth[month - 1])
        throw std::runtime_error("Unvalid day compared to month: " + date + "\n");

}

static void isNumber(std::string val, int flag) {
    errno = 0;
    char *end;
    double value = std::strtod(val.c_str(), &end);

    if (*end != '\0')
        throw std::runtime_error("Unvalid value: " + val);

    if (errno == ERANGE)
        throw std::runtime_error("Unvalid value: " + val);

    if (flag && (value < 0 || value > 1000))
        throw std::runtime_error("Unvalid value (out of range): " + val);
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

static double getValue(std::map<std::string, std::string>& data, std::string &date)
{
    std::stringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    ss >> year >> dash1 >> month >> dash2 >> day;

    ss.str("");
    ss.clear();

    ss << year << "-"
        << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day;

    std::string formatedDate = ss.str();
    
    std::map<std::string, std::string>::iterator it = data.lower_bound(formatedDate);
    if (it != data.end() && (it->first == formatedDate))
        return std::strtod(it->second.c_str(), NULL);
    
    if (it == data.begin())
        return -1;
    
    it--;

    return std::strtod(it->second.c_str(), NULL);
}

void BitcoinExchange::ShowValues(std::string fileName) {
    std::map<std::string, std::string> data;

    // store data
    try {
        getData(data);
        checkData(data);
    }
    catch (std::exception &err) {
        std::cerr << "Error: unvalid argument in .csv file => " << err.what() << std::endl;
        return ;
    }

    // get values
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: can't open file.\n";
        return ;
    }

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
        int countCol = 0;
        std::string row[2];

        while (std::getline(ss, word, '|'))
        {
            ft_strtrim(word, ' ');
            if (countCol >= 2) {
                countCol++;
                break ;
            }
            row[countCol++] = word;
        }

        if (countCol != 2) {
            std::cerr << "Error: Bad input => Unvalid columns numbers in row." << std::endl;
            continue ;
        }

        try {
            isDate(row[0]);
            isNumber(row[1], 1);
        } catch (std::exception &err) {
            std::cout << "Error: Bad input => " << err.what() << std::endl;
            continue ;
        }

        double value = getValue(data, row[0]);

        std::cout << row[0] << " => " << row[1] << " = " << (std::strtod(row[1].c_str(), NULL) * value) << std::endl;

    }
}
