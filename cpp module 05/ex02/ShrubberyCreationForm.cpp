#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", 145, 137), target("dumpName")  {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string vatTarget) : AForm("shrubbery creation", 145, 137), target(vatTarget)  {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) { (void) other; }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string ShrubberyCreationForm::getTarget() const {
    return target;
};
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outFile(this->getTarget() + "_shrubbery");

    if (!outFile.is_open())
        std::cout << "can't open the file" << std::endl;
    else {
        outFile << "  *  " << std::endl;
        outFile << " *** " << std::endl;
        outFile << "*****" << std::endl;
        outFile << "  |  " << std::endl;
        outFile.close();
    }
};
