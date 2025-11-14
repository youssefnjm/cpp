#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form(void);
        Form(std::string valName, int valSignGrade, int valExecGrade);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char *what() const throw();
        };

        void beSigned(const Bureaucrat &b);
};

std::ostream &operator << (std::ostream &out, const Form &Form);

#endif

