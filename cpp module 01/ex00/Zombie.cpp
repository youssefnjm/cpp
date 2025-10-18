/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:53:41 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/17 17:13:21 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void Zombie::setName(std::string newName) { name = newName; }
std::string Zombie::getName( void ) const { return name; }

void Zombie::announce()
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n"; 
}

Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << name << " deleted\n";
}
