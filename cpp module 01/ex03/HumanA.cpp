/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 03:32:38 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/29 05:41:06 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
        
void HumanA::attack() {
    std::cout << name <<  " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string n, Weapon &weapon) : name(n), weapon(weapon) {}

HumanA::~HumanA() {}
