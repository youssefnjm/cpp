#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

