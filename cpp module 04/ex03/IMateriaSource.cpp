#include "IMateriaSource.hpp"

// Default constructor
IMateriaSource::IMateriaSource(void) {}

// Copy constructor
IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
    (void) other;
    return ;
}

// Assignment operator overload
IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
    (void) other;
    return (*this);
}

// Destructor
IMateriaSource::~IMateriaSource(void) {}

