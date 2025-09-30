/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 03:32:19 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/29 04:59:47 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "iostream"

class Weapon
{
    private:
        std::string type;
    public:
        std::string getType( void ) const;
        void setType(std::string value);

        Weapon(std::string type);
        ~Weapon();
};

#endif