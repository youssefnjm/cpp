#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : name ("dumpName"), isSigned(false), signGrade(0), execGrade(0) {}
AForm::AForm(const AForm &other) : name(other.name),  isSigned(other.isSigned), signGrade(other.signGrade),  execGrade(other.execGrade) {}
AForm &AForm::operator=(const AForm &other) { this->isSigned = other.isSigned; return (*this); }
AForm::~AForm(void) {}

AForm::AForm(std::string valName, int valSignGrade, int valExecGrade) : name (valName), isSigned(false), signGrade(valSignGrade), execGrade(valExecGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    return ;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
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

std::ostream &operator << (std::ostream &out, const AForm &AForm) {
    out << "Name: " << AForm.getName() << ", isSigned: " << AForm.getIsSigned() << ", signGrade: " << AForm.getSignGrade() << ", execGrade: " << AForm.getExecGrade();
    return out;
};