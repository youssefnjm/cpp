#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("dumpName", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) { (void) other; }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) { (void) other; return *this; }

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::executeAction() const {
    int res = time(NULL) % 2;

    if (res)
        std::cout << this->getName() << " has been robotomized successfully" << std::endl;
    else 
        std::cout << "the robotomy failed on " << this->getName() << std::endl;
};
