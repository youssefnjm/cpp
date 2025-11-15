#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("dumpName", 25, 5) {}

// paramittrize constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) { (void) other; }

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) { (void) other; return *this; }

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {}



void PresidentialPardonForm::executeAction() const {
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};
