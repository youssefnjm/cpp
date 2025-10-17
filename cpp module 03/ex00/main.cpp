#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "constructors called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) {

};

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    (void)other;
    return (*this);
};

ClapTrap::~ClapTrap() {
    std::cout << "destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
    int damage = 5;
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap" << name << "attacks" << target << ", causing" << damage << "points of damage!" << std::endl;
    }
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints != 0 && hitPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
    }
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0)
    {
        hitPoints -= amount;
    }
};