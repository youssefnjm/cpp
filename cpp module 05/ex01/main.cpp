#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <exception>

int main()
{
    try {
        Bureaucrat b("b1", 50);
        std::cout << "Bureaucrat: " << b << std::endl;

        Form f1("f1", 10, 100);
        std::cout << "Form" << f1 << std::endl;
        
        Form f2("f1", 100, 100);
        std::cout << "Form" << f2 << std::endl;

        std::cout << std::endl;

        b.signForm(f1);
        b.signForm(f2);

    } 
    catch (std::exception &e) {
        std::cout << "exeption: " << e.what();
    }



    return (0);
}