#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45), target("dumpName")  {}

RobotomyRequestForm::RobotomyRequestForm(std::string valTarget) : AForm("robotomy request", 72, 45), target(valTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) { (void) other; }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) { (void) other; return *this; }

RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::string RobotomyRequestForm::getTarget() const {
    return target;
};
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();

    int res = time(NULL) % 2;

    if (res)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else 
        std::cout << "the robotomy failed on " << this->getTarget() << std::endl;
};
