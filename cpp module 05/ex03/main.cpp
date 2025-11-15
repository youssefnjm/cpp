#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Bureaucrat b("b", 1);

        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        b.signAForm(*rrf);
        b.executeForm(*rrf);

        delete rrf;
    } 
    catch (std::exception &e) {
        std::cout << "exeption: " << e.what();
    }

    return (0);
}