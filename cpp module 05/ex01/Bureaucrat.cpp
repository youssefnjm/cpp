#include "Bureaucrat.hpp"
#include "Form.hpp"
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

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    this->grade = other.grade;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->grade = other.grade;
    return (*this);
}

// Destructor
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
    return "grade too hight";
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
};

void Bureaucrat::signForm(Form &form){
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception &err) {
        std::cout << "the bureaucrat " << this->getName() << " couldn't sign "<< form.getName() << " because " << err.what() << std::endl; 
    }
}

std::ostream &operator << (std::ostream &out, const Form &Form) {
    out << "Name: " << Form.getName() << ", isSigned: " << Form.getIsSigned() << ", signGrade: " << Form.getSignGrade() << ", execGrade: " << Form.getExecGrade();
    return out;
};