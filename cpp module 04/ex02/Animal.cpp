#include "Animal.hpp"

// ____________________ Default constructor
Animal::Animal(void) : type("unknown")
{
    std::cout << "Animal Default constructor called" << std::endl;
    return ;
}

// ____________________ parametrize constructor
Animal::Animal(std::string setType) : type(setType)
{
    std::cout << "Animal parametrize constructor called" << std::endl;
    return ;
}

// ____________________ Copy constructor
Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    this->setType(other.getType());
}

// ____________________ Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Assignment operator called" << std::endl;
    this->setType(other.getType());
    return (*this);
}

// ____________________ Destructor
Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
    return ;
}

// ____________________ getter/stter
void Animal::setType(std::string value) { type = value; };
std::string Animal::getType() const { return type; };
