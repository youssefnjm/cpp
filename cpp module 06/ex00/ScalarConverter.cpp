#include "ScalarConverter.hpp"
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
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
        return ;
    }
    if (value == "nanf" || value == "-inff" || value == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << value.substr(0, 4) << std::endl;
        return ;
    }

    std::cout << std::fixed << std::setprecision(1);

    if (value[0] == '\0' || (value.length() == 1 && !std::isdigit(value[0]))) {
        if (value[0] > 32 && value[0] < 126)
            std::cout << "char: " << "\'" << value[0] << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(value[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value[0]) << std::endl;

        return;
    } else {
        size_t point = value.find('.', 0);
        size_t floatSign = value.find('f', 0);
        std::stringstream ss(value);

        if (point == std::string::npos && floatSign == std::string::npos)
        {
            // std::cout << "===========================INT " << std::endl;
            if (IsInt(value)) 
            {
                long tmp = std::atol(value.c_str());
                if (tmp >= 32 && tmp < 126)
                    std::cout << "char: " << "\'" << static_cast<char>(tmp) << "\'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;

                if (tmp >= -2147483648 && tmp <= 2147483647)
                    std::cout << "int: " << static_cast<int>(tmp) << std::endl;
                else
                    std::cout << "int: impossible" << std::endl;

                std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(tmp) << std::endl;
                return;
            }
        }
        else if (floatSign != std::string::npos)
        {
            // std::cout << "===========================FLOAT " << std::endl;
            if (IsFloat(value))
            {
                value = value.substr(0, floatSign);
                ss.str(value);
                ss.clear();

                float tmp;
                ss >> tmp;

                if (static_cast<long>(tmp) >= 32 && static_cast<long>(tmp) < 126)
                    std::cout << "char: " << "\'" << static_cast<char>(tmp) << "\'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;

                if (static_cast<long>(tmp) >= -2147483648 && static_cast<long>(tmp) <= 2147483647)
                    std::cout << "int: "  << static_cast<int>(tmp) << std::endl;
                else
                    std::cout << "int: impossible" << std::endl;

                std::cout << "float: " << tmp << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(tmp) << std::endl;
                return;
            }
        }
        else if (floatSign == std::string::npos && point != std::string::npos)
        {
            // std::cout << "===========================DOUBLE " << std::endl;
            if (IsDouble(value))
            {
                double tmp;
                ss >> tmp;
                if (static_cast<long>(tmp) >= 32 && static_cast<long>(tmp) < 126)
                    std::cout << "char: " << "\'" << static_cast<char>(tmp) << "\'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;

                if (static_cast<long>(tmp) >= -2147483648 && static_cast<long>(tmp) <= 2147483647)
                    std::cout << "int: " << static_cast<int>(tmp) << std::endl;
                else
                    std::cout << "int: impossible" << std::endl;

                std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
                std::cout << "double: " << tmp << std::endl;
                return;
            }
        }
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
