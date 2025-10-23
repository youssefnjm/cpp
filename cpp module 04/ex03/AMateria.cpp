#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void)
{
    std::cout << "AMateria Default constructor called" << std::endl;
}

// paramitrize constructor
AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria paramitrize constructor called" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other.getType())
{
    std::cout << "AMateria Copy constructor called" << std::endl;
    (void) other;
}

// Assignment operator overload
AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
AMateria::~AMateria(void)
{
    std::cout << "AMateria Destructor called" << std::endl;
    return ;
}

// _______________ getter
std::string const &AMateria::getType() const { return _type; };

// _______________ member function
void AMateria::use(ICharacter& target) {
    std::cout << "* " << target.getName() << " use unknown material *" << std::endl;
};