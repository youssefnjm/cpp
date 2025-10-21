#include "Dog.hpp"

// ____________________ Default constructor
Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog Default constructor called" << std::endl;}

// ____________________ Copy constructor
Dog::Dog(const Dog &other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    (void) other;}

// ____________________ Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// ____________________ Destructor
Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
}

// ____________________ member finction
void Dog::makeSound() const {
    std::cout << "Dog barks" << std::endl;
}
