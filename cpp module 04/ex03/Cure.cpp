#include "Cure.hpp"

// Default constructor
Cure::Cure(void) : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria("cure")
{
    (void) other;
    return ;
}

// Assignment operator overload
Cure &Cure::operator=(const Cure &other)
{
    (void) other;
    return (*this);
}

// Destructor
Cure::~Cure(void) {}

// _______________ member function
AMateria* Cure::clone() const {
    AMateria* cure = new Cure();
    return (cure);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
