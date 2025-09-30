/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:25:01 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/29 00:56:21 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main()
{
    Zombie *z1;
    
    z1 = newZombie("zombie-1");
    z1->announce();
    randomChump("zombie-2");
    delete z1;
    return (0);
}
