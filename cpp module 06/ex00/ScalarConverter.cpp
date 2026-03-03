#include "ScalarConverter.hpp"
#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return (*this); }
ScalarConverter::~ScalarConverter(void) {}

static int IsInt(std::string str)
{
	int i = 0;
	size_t res = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
        res = res * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

static int IsFloat(std::string str)
{
	int i = 0;
    int countP = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
        if (str[i] == '.')
            countP++;
        if (str[i] == 'f' && str[i + 1] != '\0')
            return 0;
		if ((str[i] != 'f' && str[i] != '.') && isdigit(str[i]) == 0)
			return (0);
		i++;
	}
    if (countP > 1)
        return 0;

	return (1);
}

static int IsDouble(std::string str)
{
	int i = 0;
    int countP = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
        if (str[i] == '.')
            countP++;

		if (str[i] != '.' && isdigit(str[i]) == 0)
			return (0);
		i++;
	}

    if (countP != 1)
        return 0;

	return (1);
}

void ScalarConverter::convert(std::string value) {
    if (value == "nan" || value == "-inf" || value == "+inf") {
        std::cout << "char:   impossible" << "\n";
        std::cout << "int:    impossible" << "\n";
        std::cout << "float:  " << value << "f" << "\n";
        std::cout << "double: " << value << "\n";
        return ;
    }
    if (value == "nanf" || value == "-inff" || value == "+inff") {
        std::cout << "char:   impossible" << "\n";
        std::cout << "int:    impossible" << "\n";
        std::cout << "float:  " << value << "\n";
        if (value == "nanf")
            std::cout << "double: " << value.substr(0, 3) << "\n";
        else
            std::cout << "double: " << value.substr(0, 4) << "\n";
        return ;
    }

    std::cout << std::fixed << std::setprecision(1);
    errno = 0;

    if (value[0] == '\0' || (value.length() == 1 && !std::isdigit(value[0]))) {
        if (value[0] > 32 && value[0] < 126)
            std::cout << "char:   " << "\'" << value[0] << "\'" << "\n";
        else
            std::cout << "char:   Non displayable" << "\n";
        std::cout << "int:    " << static_cast<int>(value[0]) << "\n";
        std::cout << "float:  " << static_cast<float>(value[0]) << "f" << "\n";
        std::cout << "double: " << static_cast<double>(value[0]) << "\n";

        return ;
    }

    size_t point = value.find('.', 0);
    size_t floatSign = value.find('f', 0);
    std::stringstream ss(value);

    if (point == std::string::npos && floatSign == std::string::npos && IsInt(value))
    {
        // std::cout << "===========================INT " << "\n";
        long long tmp = std::strtol(value.c_str(), NULL, 10);
        if (errno != ERANGE) {
            if (tmp >= 32 && tmp < 126)
                std::cout << "char:   " << "\'" << static_cast<char>(tmp) << "\'" << "\n";
            else
                std::cout << "char:   Non displayable" << "\n";

            if (tmp >= -2147483648 && tmp <= 2147483647)
                std::cout << "int:    " << static_cast<int>(tmp) << "\n";
            else
                std::cout << "int:    impossible" << "\n";

            std::cout << "float:  " << static_cast<float>(tmp) << "f" << "\n";
            std::cout << "double: " << static_cast<double>(tmp) << "\n";
            
            return;
        }
    }
    else if (floatSign != std::string::npos && IsFloat(value))
    {
        // std::cout << "===========================FLOAT " << "\n";
        value = value.substr(0, floatSign);
        ss.str(value);
        ss.clear();

        float tmp;
        ss >> tmp;

        if (static_cast<long>(tmp) >= 32 && static_cast<long>(tmp) < 126)
            std::cout << "char:   " << "\'" << static_cast<char>(tmp) << "\'" << "\n";
        else
            std::cout << "char:   Non displayable" << "\n";

        if (static_cast<long>(tmp) >= -2147483648 && static_cast<long>(tmp) <= 2147483647)
            std::cout << "int:    "  << static_cast<int>(tmp) << "\n";
        else
            std::cout << "int:    impossible" << "\n";

        std::cout << "float:  " << tmp << "f" << "\n";
        std::cout << "double: " << static_cast<double>(tmp) << "\n";
        return;
    }
    else if (floatSign == std::string::npos && point != std::string::npos && IsDouble(value))
    {
        // std::cout << "===========================DOUBLE " << "\n";
        double tmp;
        ss >> tmp;
        if (static_cast<long>(tmp) >= 32 && static_cast<long>(tmp) < 126)
            std::cout << "char:   " << "\'" << static_cast<char>(tmp) << "\'" << "\n";
        else
            std::cout << "char:   Non displayable" << "\n";

        if (static_cast<long>(tmp) >= -2147483648 && static_cast<long>(tmp) <= 2147483647)
            std::cout << "int:    " << static_cast<int>(tmp) << "\n";
        else
            std::cout << "int:    impossible" << "\n";

        std::cout << "float:  " << static_cast<float>(tmp) << "f" << "\n";
        std::cout << "double: " << tmp << "\n";
        return;
    }
    

    std::cout << "char:   impossible" << "\n";
    std::cout << "int:    impossible" << "\n";
    std::cout << "float:  impossible" << "\n";
    std::cout << "double: impossible" << "\n";
}
