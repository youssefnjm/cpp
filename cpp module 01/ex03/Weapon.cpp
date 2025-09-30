/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 03:32:10 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/29 05:02:28 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string Weapon::getType() const { return type; }
void Weapon::setType(std::string value) { type = value; }

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}
