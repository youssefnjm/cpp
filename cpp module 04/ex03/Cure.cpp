#include "Cure.hpp"

// Default constructor
Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Cure::Cure(const Cure &other)
{
    std::cout << "Cure Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Cure::~Cure(void)
{
    std::cout << "Cure Destructor called" << std::endl;
    return ;
}

// _______________ member function
AMateria* Cure::clone() const {
    AMateria* cure = new Cure();
    return (cure);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
};
