/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:58:33 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/09 16:48:10 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string val) { name = val; }
std::string Zombie::getName( void ) const { return name; }

void Zombie::announce()
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n"; 
}

Zombie::Zombie() {}

Zombie::~Zombie() {   
    std::cout << name << " deleted\n";
}
