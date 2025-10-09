/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:20:46 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/09 16:33:47 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* newZombie( std::string name ) {
    Zombie* tmp = new Zombie;
    tmp->setName(name);
    return tmp;
}
