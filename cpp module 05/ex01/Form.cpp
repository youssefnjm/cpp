#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name ("dumpName"), isSigned(false), signGrade(0), execGrade(0) {}
Form::Form(const Form &other) : name(other.name),  isSigned(other.isSigned), signGrade(other.signGrade),  execGrade(other.execGrade) {}
Form &Form::operator=(const Form &other) { this->isSigned = other.isSigned; return (*this); }
Form::~Form(void) {}

Form::Form(std::string valName, int valSignGrade, int valExecGrade) : name (valName), isSigned(false), signGrade(valSignGrade), execGrade(valExecGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    return ;
}


const char *Form::GradeTooHighException::what() const throw()
{
    return "grade too high";
};
const char *Form::GradeTooLowException::what() const throw()
{
    return "grade too low";
};

std::string Form::getName() const { return name; };
bool Form::getIsSigned() const { return isSigned; };
int Form::getSignGrade() const { return signGrade; };
int Form::getExecGrade() const { return execGrade; };

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= this->getSignGrade())
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
};

std::ostream &operator << (std::ostream &out, const Form &Form) {
    out << "Name: " << Form.getName() << ", isSigned: " << Form.getIsSigned() << ", signGrade: " << Form.getSignGrade() << ", execGrade: " << Form.getExecGrade();
    return out;
};