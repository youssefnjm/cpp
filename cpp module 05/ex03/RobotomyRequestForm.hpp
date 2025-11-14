#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void executeAction() const;
};

#endif

