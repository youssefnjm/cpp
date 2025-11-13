#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void) : type("unknown")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

// parametrize constructor
WrongAnimal::WrongAnimal(std::string setType) : type(setType)
{
    std::cout << "WrongAnimal parametrize constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->setType(other.getType());
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Assignment operator called" << std::endl;
    this->setType(other.getType());
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

// ____________________ getter/stter
void WrongAnimal::setType(std::string value) { type = value; };
std::string WrongAnimal::getType() const { return type; };

// ____________________ member function
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal unknown" << std::endl;
}
