#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5), target("dumpName") {}

PresidentialPardonForm::PresidentialPardonForm(std::string valTarget) :  AForm("presidential pardon", 25, 5), target(valTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) { (void) other; }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) { (void) other; return *this; }

PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::string PresidentialPardonForm::getTarget() const {
    return target;
};

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();

    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};
