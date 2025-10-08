/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:58:07 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/06 22:22:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie *z;
    
    z = zombieHorde(5, "zombies");
    for (int i = 0; i < 5; i++) {
        z[i].announce();
    }
    delete[] z;
    return (0);
}
