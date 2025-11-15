#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

// Default constructor
Intern::Intern(void) {}

// Copy constructor
Intern::Intern(const Intern &other) { (void) other; }

// Assignment operator overload
Intern &Intern::operator=(const Intern &other) {(void) other; return (*this);}

// Destructor
Intern::~Intern(void) {}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not fount";
}

AForm *Intern::createShrubbery(std::string target) {
    return (new ShrubberyCreationForm(target));
};
AForm *Intern::createRobotomy(std::string target) {
    return (new RobotomyRequestForm(target));
};
AForm *Intern::createPresidential(std::string target) {
    return (new PresidentialPardonForm(target));
};

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string forms[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

    AForm* (Intern::*ptr[3])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential,
    };

    int i = -1;
    while (++i < 3)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*ptr[i])(target);
        }
    };

    throw FormNotFoundException();
};