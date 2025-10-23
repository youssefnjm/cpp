#include "Character.hpp"
#include "List.hpp"

// Default constructor
Character::Character(void) : _name("bot")
{
    std::cout << "Character Default constructor called" << std::endl;
    _inventory[0] = NULL;
    _inventory[1] = NULL;
    _inventory[2] = NULL;
    _inventory[3] = NULL;
    return ;
}

// paramitrize constructor
Character::Character(std::string val) : _name(val)
{
    std::cout << "Character paramitrize constructor called" << std::endl;
    _inventory[0] = NULL;
    _inventory[1] = NULL;
    _inventory[2] = NULL;
    _inventory[3] = NULL;
};

// Copy constructor
Character::Character(const Character &other) : _name(other.getName())
{
    std::cout << "Character Copy constructor called" << std::endl;
    if (other._inventory[0])
        _inventory[0] = other._inventory[0]->clone();
    else
        _inventory[0] = NULL;
    if (other._inventory[1])
        _inventory[1] = other._inventory[1]->clone();
    else
        _inventory[1] = NULL;
    if (other._inventory[2])
        _inventory[2] = other._inventory[2]->clone();
    else
        _inventory[2] = NULL;
    if (other._inventory[3])
        _inventory[3] = other._inventory[3]->clone();
    else
        _inventory[3] = NULL;
    return ;
}

// Assignment operator overload
Character &Character::operator=(const Character &other)
{
    std::cout << "Character Assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            List::addLast(_inventory[i]);
        if (other._inventory[0])
            _inventory[0] = other._inventory[0]->clone();
        else
            _inventory[0] = NULL;
        if (other._inventory[1])
            _inventory[1] = other._inventory[1]->clone();
        else
            _inventory[1] = NULL;
        if (other._inventory[2])
            _inventory[2] = other._inventory[2]->clone();
        else
            _inventory[2] = NULL;
        if (other._inventory[3])
            _inventory[3] = other._inventory[3]->clone();
        else
            _inventory[3] = NULL;
    }
    return (*this);
}

// Destructor
Character::~Character(void)
{
    std::cout << "Character Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        List::addLast(_inventory[i]);
    
    return ;
}

// _________________ getter
std::string const &Character::getName() const { return (_name); };

// _________________ member function
void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
    std::cout << "slot is full" << std::endl;
};

void Character::unequip(int idx) {
    if ((idx >= 0 && idx <= 3))
    {
        List::addLast(_inventory[idx]);
        _inventory[idx] = NULL;
        return ;
    }
    std::cout << "slot index out of range" << std::endl;
};

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx <= 3 &&  _inventory[idx])
    {
        _inventory[idx]->use(target);
        return ;
    }
    if ( _inventory[idx])
    {
        std::cout << "empty slot" << std::endl;
        return ;
    }
    std::cout << "slot index out of range" << std::endl;
};