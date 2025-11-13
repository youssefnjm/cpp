#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat(void);
        Cat(const Cat& other);
        Cat &operator=(const Cat &other);
        ~Cat();

        void makeSound() const;
    
        void setIdeas(std::string value, int index);
        std::string getIdeas(int index) const;
};

#endif

