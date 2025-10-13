/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:58:42 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/12 11:46:49 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *tmp = new Zombie [N];

    for (int i = 0; i < N; i++) {
        tmp[i].setName(name);
    }
    return (tmp);
}
