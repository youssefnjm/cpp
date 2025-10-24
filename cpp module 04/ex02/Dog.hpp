#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog(void);
        Dog(const Dog& other);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound() const;

        void setIdeas(std::string value, int index);
        std::string getIdeas(int index) const;
};

#endif

