/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:44:46 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/30 01:05:34 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "unvalid paramettre namber\n";
        return (1);
    }

    Harl harl;

    std::string level = av[1]; 
    int order = (level == "DEBUG") ? 0 : (level == "INFO") ? 1 : (level == "WARNING") ? 2 : (level == "ERROR") ? 3 : 4;

    switch (order)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.debug();
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.info();
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.warning();
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.error();
            break ;
        case 4:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

    }
    return (0);
}