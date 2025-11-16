#include "ScalarConverter.hpp"
#include <cerrno>
#include <cfloat>
#include <climits>
#include <iomanip>

ScalarConverter::ScalarConverter(void)  {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void) other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void) other; return (*this); }
ScalarConverter::~ScalarConverter(void) {}

static void displayChar(long num) {
    if (num < 0 || num > 255)
        std::cout << "char: impossible" << std::endl;
    else if (!((num >= 32 && num <= 126) || num == 9))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "\'" << static_cast<char>(num) << "\'" << std::endl;
}

static void displayInt(long num) {
    if (num > INT_MIN && num < INT_MAX)
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

static void displayFlaot(double num) {
    float f = static_cast<float>(num);
    if (f > -FLT_MAX && f < FLT_MAX)
        std::cout << "flaot: " << f << 'f' << std::endl;
    else
        std::cout << "flaot: impossible" << std::endl;
}

static void displayDouble(double num) {
    double f = static_cast<double>(num);
    if (f > -DBL_MAX && f < DBL_MAX)
        std::cout << "double: " << f << 'f' << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

static void displayImposible() {
    std::cout << "char: impossible"<< std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string value) {
    if (value == "nan" || value == "-inf" || value == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
        return ;
    }
    if (value == "nanf" || value == "-inff" || value == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << value.substr(0, 4) << std::endl;
        return ;
    }

    std::cout <<std::fixed << std::setprecision(1);

    if (value[0] == '\0' || (value.length() == 1 && std::isalpha(value[0])))
    {

        char a = (value.c_str())[0];
        if ((value[0] > 32 && value[0] < 126) || value[0] == ' ' || value[0] == '\t')
            std::cout << "char: " << "\'" << a << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(a) << std::endl;
        std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(a) << std::endl;
        return ;
    }
    else
    {
        char *end = NULL;
        char *point = (char *)std::strchr(value.c_str(), '.');

        double num = std::strtod(value.c_str(), &end);
        
        if (point != NULL && *end == '\0')
        {
            displayChar(num);
            displayInt(num);
            displayFlaot(num);
            displayDouble(num);
            return ;
        }
        else if (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE)
        {
            displayChar(num);
            displayInt(num);
            displayFlaot(num);
            displayDouble(num);
            return ;
        }
        else if (point == NULL)
        {
            long num =std::strtol(value.c_str(), &end, 10);

            if (*end == '\0' && errno != ERANGE)
            {
                displayChar(num);
                displayInt(num);
                displayFlaot(num);
                displayDouble(num);
                return ;
            }
        }
    }
    displayImposible();
}
