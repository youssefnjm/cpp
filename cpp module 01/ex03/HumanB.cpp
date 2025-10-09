/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 03:33:26 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/09 17:06:35 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
        
void HumanB::attack() {
    if (weapon)
        std::cout << name <<  " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &we) { weapon = &we; }

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}