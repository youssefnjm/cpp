#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap p2("player2");

    p2.takeDamage(1);
    p2.guardGate();
    p2.beRepaired(10);
    p2.attack("player1");

    return (0);
}