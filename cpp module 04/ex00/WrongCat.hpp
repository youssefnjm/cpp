#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private:
        std::string type;
    public:
        WrongCat(void);
        WrongCat(const WrongCat& other);
        WrongCat &operator=(const WrongCat &other);
        ~WrongCat();

        void makeSound() const;
};

#endif

