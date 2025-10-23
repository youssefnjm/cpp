#include "IMateriaSource.hpp"

// Default constructor
IMateriaSource::IMateriaSource(void)
{
    std::cout << "IMateriaSource Default constructor called" << std::endl;
    return ;
}

// Copy constructor
IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
    std::cout << "IMateriaSource Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
    std::cout << "IMateriaSource Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
IMateriaSource::~IMateriaSource(void)
{
    std::cout << "IMateriaSource Destructor called" << std::endl;
    return ;
}

