#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("dumpName", 145, 137) {}

// paramittrize constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) { (void) other; }

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) { (void)other; return (*this); }

// Destructor
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
