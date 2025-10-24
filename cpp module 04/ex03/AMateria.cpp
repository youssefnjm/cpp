#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void) {}

// paramitrize constructor
AMateria::AMateria(std::string const & type) : _type(type) {}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other.getType()) { (void) other; }

// Assignment operator overload
AMateria &AMateria::operator=(const AMateria &other)
{
    (void) other;
    return (*this);
}

// Destructor
AMateria::~AMateria(void) {}

// _______________ getter
std::string const &AMateria::getType() const { return _type; };

// _______________ member function
void AMateria::use(ICharacter& target) {
    std::cout << "* " << target.getName() << " use unknown material *" << std::endl;
};