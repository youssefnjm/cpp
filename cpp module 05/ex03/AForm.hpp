#ifndef AForm_HPP
# define AForm_HPP
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm(void);
        AForm(std::string valName, int valSignGrade, int valExecGrade);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

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
        class FormNotSignedException : public std::exception {
            const char *what() const throw();
        };

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator << (std::ostream &out, const AForm &AForm);

#endif
