#include "Brain.hpp"

// ____________________ Default constructor
Brain::Brain(void)
{
    std::cout << "Brain Default constructor called" << std::endl;
}

// ____________________ Copy constructor
Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->setIdeas(other.getIdeas(i), i);
    }
}

// ____________________ Assignment operator overload
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
        {
            this->setIdeas(other.getIdeas(i), i);
        }
    }
    return (*this);
}

// ____________________ Destructor
Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
}

// ____________________ getter/setter
void Brain::setIdeas(std::string value, int index) {
    if (index < 100)
        ideas[index] = value;
};
std::string Brain::getIdeas(int index) const { 
    if (index < 100)
        return ideas[index];
    return NULL;
};

