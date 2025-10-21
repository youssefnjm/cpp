#include "Cat.hpp"

// ____________________ Default constructor
Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
    brain = new Brain();
}

// ____________________ Copy constructor
Cat::Cat(const Cat &other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    if (this->brain)
    {
        delete this->brain;
        this->brain = NULL;
    }
    this->brain = new Brain(*other.brain);
    this->setType(other.getType());
}

// ____________________ Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Assignment operator called" << std::endl;
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
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
    if (brain)
        delete brain;
}

// ____________________ member finction
void Cat::makeSound() const {
    std::cout << "Cat meows" << std::endl;
}