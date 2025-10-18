#include "FragTrap.hpp"

// _______________FragTrap constractor 
FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap Destructor of " << name << " called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
};

FragTrap::FragTrap(std::string n) : ClapTrap(n) {
    std::cout << "FragTrap Destructor of " << name << " called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
};

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap Copy constructor of" << name << "called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return ;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap assignment operator of" << name << "called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor of " << name << " called" << std::endl;
    return ;
}

// _______________member function of FragTrap
void FragTrap::highFivesGuys() {
   std::cout << "FragTrap " << name << " high-fives!" << std::endl; 
};

void FragTrap::attack(const std::string& target) {
    if (hitPoints <= 0)
        return ;
    if (energyPoints > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }else 
        std::cout << name << " is out of energy!" << std::endl;
};

void FragTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0)
        return ;
    if (energyPoints != 0)
    {
        std::cout << "FragTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
        energyPoints--;
        hitPoints += amount;
    }else 
        std::cout << name << " is out of energy!" << std::endl;
};

void FragTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0)
    {
        std::cout << "FragTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
    }
};
