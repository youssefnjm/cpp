#include "Ice.hpp"

// Default constructor
Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Ice::Ice(const Ice &other)
{
    std::cout << "Ice Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Ice::~Ice(void)
{
    std::cout << "Ice Destructor called" << std::endl;
    return ;
}

// _______________ member function
AMateria* Ice::clone() const {
    AMateria* ice = new Ice();
    return (ice);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};

