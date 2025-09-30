/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:44:58 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/30 00:59:43 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
#define HARL_HPP

#include "iostream"

class Harl
{
    public:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif