#include "Ice.hpp"

// Default constructor
Ice::Ice(void) : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria("ice")
{
    (void) other;
    return ;
}

// Assignment operator overload
Ice &Ice::operator=(const Ice &other)
{
    (void) other;
    return (*this);
}

// Destructor
Ice::~Ice(void) {}

// _______________ member function
AMateria* Ice::clone() const {
    AMateria* ice = new Ice();
    return (ice);
};

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};

