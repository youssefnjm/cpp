#include "Dog.hpp"

// ____________________ Default constructor
Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog Default constructor called" << std::endl;
    brain = new Brain();
}

// ____________________ Copy constructor
Dog::Dog(const Dog &other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->setType(other.getType());
}

// ____________________ Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    if (this != &other) {
        if (this->brain)
        {
            delete this->brain;
            this->brain = NULL;
        }
        this->brain = new Brain(*other.brain);
        this->setType(other.getType());
    }
    return (*this);
}

// ____________________ Destructor
Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
    if (brain)
        delete brain;
}

// ____________________ getter/setter
void Dog::setIdeas(std::string value, int index) {
    if (index >= 0 && index < 100)
        brain->setIdeas(value, index);
};
std::string Dog::getIdeas(int index) const { 
    if (index >= 0 && index < 100)
        return brain->getIdeas(index);
    return "";
};

// ____________________ member finction
void Dog::makeSound() const {
    std::cout << "Dog barks" << std::endl;
}
