/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:19:07 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/29 00:24:58 by ynoujoum         ###   ########.fr       */
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
    
        void setName(std::string name);
        std::string getname( void ) const;

        Zombie();
        ~Zombie();
};

#endif