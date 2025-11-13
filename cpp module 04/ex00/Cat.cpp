#include "Cat.hpp"

// ____________________ Default constructor
Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
}

// ____________________ Copy constructor
Cat::Cat(const Cat &other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->setType(other.getType());
}

// ____________________ Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    this->setType(other.getType());
    return (*this);
}

// ____________________ Destructor
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
}

// ____________________ member function
void Cat::makeSound() const {
    std::cout << "Cat meows" << std::endl;
}