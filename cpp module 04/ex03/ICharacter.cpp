#include "ICharacter.hpp"

// Default constructor
ICharacter::ICharacter(void) {}

// Copy constructor
ICharacter::ICharacter(const ICharacter &other)
{
    (void) other;
    return ;
}

// Assignment operator overload
ICharacter &ICharacter::operator=(const ICharacter &other)
{
    (void) other;
    return (*this);
}

// Destructor
ICharacter::~ICharacter(void) {}

