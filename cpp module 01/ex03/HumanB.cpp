/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 03:33:26 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/29 05:40:54 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
        
void HumanB::attack() {
    std::cout << name <<  " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &we) { weapon = &we; }

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}