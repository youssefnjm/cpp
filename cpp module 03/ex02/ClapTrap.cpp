#include "ClapTrap.hpp"

// _______________ClapTrap constractor 
ClapTrap::ClapTrap() : name("bot"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructors of " << name << " called" << std::endl;
};

ClapTrap::ClapTrap(std::string n) : name(n), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructors of " << name << " called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor of" << name << "called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator of " << name << "called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor of " << name << " called" << std::endl;
    return ;
}

// _______________member function of ClapTrap

void ClapTrap::attack(const std::string& target) {
    if (hitPoints <= 0)
        return ;
    if (energyPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }else 
        std::cout << name << " is out of energy!" << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0)
        return ;
    if (energyPoints != 0)
    {
        std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
        energyPoints--;
        hitPoints += amount;
    }else 
        std::cout << name << " is out of energy!" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
    }
};
