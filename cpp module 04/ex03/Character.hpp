#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
    protected:
        std::string const _name;
        AMateria* _inventory[4];
    public:
        Character(void);
        Character(std::string val);
        Character(const Character& other);
        Character &operator=(const Character &other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif

