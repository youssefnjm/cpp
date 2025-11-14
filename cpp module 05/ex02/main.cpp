#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    try {
        Bureaucrat b("b1", 50);
        std::cout << "Bureaucrat: " << b << std::endl;

        // AForm f1("f1", 10, 100);
        // std::cout << "AForm" << f1 << std::endl;

        std::cout << std::endl;
        PresidentialPardonForm f1("pardonForm");
        RobotomyRequestForm f2("roboForm");
        ShrubberyCreationForm f3("treeForm");

        std::cout << "AForm " << f1 << std::endl;
        std::cout << "AForm " << f2 << std::endl;
        std::cout << "AForm " << f3 << std::endl;
        
        std::cout << std::endl;

        b.signAForm(f1);
        b.signAForm(f2);
        b.signAForm(f3);
        
        std::cout << std::endl;

        b.executeForm(f1);
        b.executeForm(f2);
        b.executeForm(f3);
    } 
    catch (std::exception &e) {
        std::cout << "exeption: " << e.what();
    }

    return (0);
}