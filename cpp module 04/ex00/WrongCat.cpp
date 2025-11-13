#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->setType(other.getType());
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongAnimal Assignment operator called" << std::endl;
    this->setType(other.getType());
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

// ____________________ member function
void WrongCat::makeSound() const {
    std::cout << "WrongCat Meow" << std::endl;
}
