#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot;
    ClapTrap p1("player1");

    p1.attack("bot");
    bot.takeDamage(0);
    bot.attack("player1");
    p1.takeDamage(1000);
    p1.beRepaired(5);
    p1.attack("bot");
    return (0);
}