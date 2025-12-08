#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("dumpName", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) { (void) other; }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) { (void) other; return *this; }

PresidentialPardonForm::~PresidentialPardonForm(void) {}



void PresidentialPardonForm::executeAction() const {
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};
