#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
// Default constructor
Bureaucrat::Bureaucrat(void) : name("dumpName"), grade(150) {}

Bureaucrat::Bureaucrat(std::string nameVal, int gradeVal) : name(nameVal), grade(gradeVal)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) { this->grade = other.grade; return (*this); }
Bureaucrat::~Bureaucrat(void) {}

std::ostream &operator << (std::ostream &out, const Bureaucrat &Bureaucrat) {
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return out;
};

std::string Bureaucrat::getName() const { return (name); };
int Bureaucrat::getGrade() const { return (grade); };

void Bureaucrat::incrementGrade() {
    if ((grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;

};

void Bureaucrat::decrementGrade() {
    if ((grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
};
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
};

void Bureaucrat::signAForm(AForm &AForm){
    try {
        AForm.beSigned(*this);
        std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
    } catch (std::exception &err) {
        std::cout << this->getName() << " couldn't sign " << AForm.getName() << " because " << err.what() << "." << std::endl; 
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << this->getName() << " can't executed " << form.getName() << " form because :" << e.what() << std::endl;
    } 
};
