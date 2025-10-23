#include "ICharacter.hpp"

// Default constructor
ICharacter::ICharacter(void)
{
    std::cout << "ICharacter Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ICharacter::ICharacter(const ICharacter &other)
{
    std::cout << "ICharacter Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
ICharacter &ICharacter::operator=(const ICharacter &other)
{
    std::cout << "ICharacter Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ICharacter::~ICharacter(void)
{
    std::cout << "ICharacter Destructor called" << std::endl;
    return ;
}

