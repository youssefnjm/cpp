#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    private:
        std::string type;
    public:
        Animal(void);
        Animal(std::string setType);
        Animal(const Animal& other);
        Animal &operator=(const Animal& other);
        virtual ~Animal();

        std::string getType() const;
        void setType(std::string value);
    
        virtual void makeSound() const = 0;
};

#endif

