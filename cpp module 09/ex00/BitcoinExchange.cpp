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
        throw std::runtime_error("Unvalid value (contain chars): " + val);

    if (errno == ERANGE)
        throw std::runtime_error("Unvalid value (overflow): " + val);

    if (flag && (value < 0 || value > 1000))
        throw std::runtime_error("Unvalid value (out of range): " + val);
}

static double getValue(std::map<std::string, std::string>& dataBase, std::string &date) {
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
    
    std::map<std::string, std::string>::iterator it = dataBase.lower_bound(formatedDate);
    if (it != dataBase.end() && (it->first == formatedDate))
        return std::strtod(it->second.c_str(), NULL);
    
    if (it == dataBase.begin())
        return -1;
    
    it--;

    return std::strtod(it->second.c_str(), NULL);
}

static std::map<std::string, std::string> getData() {
    std::map<std::string, std::string> dataBase;

    std::ifstream dataBaseFile("data.csv");
    if (!dataBaseFile.is_open())
        throw std::runtime_error("can't open file!");

    std::string buffer;
    if (!std::getline(dataBaseFile, buffer, '\n'))
        throw std::runtime_error("file is empty!");

    while (std::getline(dataBaseFile, buffer, '\n')) {

        std::stringstream ss(buffer);
        std::map<int, std::string> row;

        int countColumn = 0;
        std::string column;
        while (std::getline(ss, column, ',')) {
            
            if (column.empty())
                throw std::runtime_error("unvalid syntax format in csv database");

            row[countColumn++] = column;
        }

        if (countColumn != 2) {
            throw std::runtime_error("Unvalid column number in csv database");
        }

        dataBase[row[0]] = row[1];
    }
    return dataBase;
}

void BitcoinExchange::ShowValues(std::string fileName) {
    // store data from datavbase
    std::map<std::string, std::string> dataBase = getData();
    
    std::map<std::string, std::string>::iterator dataBaseIt = dataBase.begin();
    std::map<std::string, std::string>::iterator dataBaseitEnd = dataBase.end();
    while (dataBaseIt != dataBaseitEnd) {
        isDate(dataBaseIt->first);
        isNumber(dataBaseIt->second, 0);
        dataBaseIt++;
    }

    // get values
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
        throw std::runtime_error("Error: can't open file.");

    std::string buffer;
    if (!std::getline(inputFile, buffer, '\n'))
        throw std::runtime_error("Error: input file is empty!");

    while (std::getline(inputFile, buffer, '\n')) {
        std::stringstream ss(buffer);
        std::map<int, std::string> row;
        std::string column;
        int countCol = 0;

        while (std::getline(ss, column, '|'))
        {
            ft_strtrim(column, ' ');
            row[countCol++] = column;
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

        double value = getValue(dataBase, row[0]);

        std::cout << row[0] 
                << " => " << row[1]
                << " = " << (std::strtod(row[1].c_str(), NULL) * value)
                << std::endl;
    }
}
