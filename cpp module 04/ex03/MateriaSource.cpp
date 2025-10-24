#include "MateriaSource.hpp"
#include "List.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
    _inventory[0] = NULL;
    _inventory[1] = NULL;
    _inventory[2] = NULL;
    _inventory[3] = NULL;
    return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
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
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
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

    return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        List::addLast(_inventory[i]);
    return ;
}

// _________________ member function
void MateriaSource::learnMateria(AMateria *tmp) {
    if (!tmp)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = tmp;
            return ;
        }
    }
    List::addLast(tmp);
};

AMateria* MateriaSource::createMateria(std::string material) {
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] && _inventory[i]->getType() == material)
        {
            AMateria* tmp = _inventory[i]->clone();
            return tmp;
        }
    }
    return (NULL);
};
