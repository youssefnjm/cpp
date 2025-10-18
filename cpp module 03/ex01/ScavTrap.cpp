#include "ScavTrap.hpp"

// _______________ScavTrap constractor 
ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap constructor of " << name << " called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
};

ScavTrap::ScavTrap(std::string n) : ClapTrap(n) {
    std::cout << "ScavTrap constructor of " << name << " called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy constructor of" << name << "called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator of" << name << "called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor of " << name << " called" << std::endl;
    return ;
}

// _______________member function of ScavTrap

void ScavTrap::guardGate() {
   std::cout << "ScavTrap " << name << " Gate keeper mode" << std::endl; 
};

void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0)
        return ;
    if (energyPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }else 
        std::cout << name << " is out of energy!" << std::endl;
};

void ScavTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0)
        return ;
    if (energyPoints != 0)
    {
        std::cout << "ScavTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
        energyPoints--;
        hitPoints += amount;
    }else 
        std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
};

void ScavTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0)
    {
        std::cout << "ScavTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
    }
};
