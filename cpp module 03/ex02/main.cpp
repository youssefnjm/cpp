#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap p2("player2");

    p2.takeDamage(1);
    p2.highFivesGuys();
    p2.beRepaired(10);
    p2.attack("player1");

    return (0);
}