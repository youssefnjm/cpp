#include "./Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat a;

        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.decrementGrade();
        a.decrementGrade();
    } 
    catch (std::exception &e) {
        std::cout << "exception from a: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b("b1", 200);

        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << "exception from b: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat c("b2", 1);

        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        c.incrementGrade();
    } 
    catch (std::exception &e) {
        std::cout << "exception from c: " << e.what() << std::endl;
    }

    return (0);
}