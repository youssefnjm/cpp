/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:20:46 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/12 11:47:10 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* newZombie( std::string name ) {
    Zombie* tmp = new Zombie(name);
    tmp->setName(name);
    return tmp;
}
