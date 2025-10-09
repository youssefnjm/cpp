/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:58:56 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/09 16:58:31 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie
{
    private:
        std::string name;
    public:
        void announce( void );
    
        void setName(std::string val);
        std::string getName( void ) const;

        Zombie();
        ~Zombie();
};

#endif