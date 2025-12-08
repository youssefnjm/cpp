#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("dumpName", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) { (void) other; }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream outFile(this->getName() + "_shrubbery");

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
