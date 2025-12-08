#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(void) : name("dumpName"), grade(150) {}

Bureaucrat::Bureaucrat(std::string nameVal, int gradeVal) : name(nameVal) {
    if (gradeVal > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (gradeVal < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade = gradeVal;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

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

std::ostream &operator << (std::ostream &out, const Bureaucrat &Bureaucrat) {
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return out;
};