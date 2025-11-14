#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm(void) : name ("dumpName"), isSigned(false), signGrade(0), execGrade(0) {}

AForm::AForm(std::string valName, int valSignGrade, int valExecGrade) : name (valName), isSigned(false), signGrade(valSignGrade), execGrade(valExecGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    return ;
}

// Copy constructor
AForm::AForm(const AForm &other) : name ("dumpName"), signGrade(0), execGrade(0)
{
    this->isSigned = other.isSigned;
    return ;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
    this->isSigned = other.isSigned;
    return (*this);
}

// Destructor
AForm::~AForm(void) {}


const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade too hight";
};
const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
};
const char *AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
};

std::string AForm::getName() const { return name; };
bool AForm::getIsSigned() const { return isSigned; };
int AForm::getSignGrade() const { return signGrade; };
int AForm::getExecGrade() const { return execGrade; };

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= this->getSignGrade())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
};

void AForm::execute(Bureaucrat const &executor) const {
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (this->getSignGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();

    executeAction();
};