#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    private:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string setType);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();

        std::string getType() const;
        void setType(std::string value);

        void makeSound() const;
};

#endif

