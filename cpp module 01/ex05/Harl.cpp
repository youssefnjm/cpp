/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:07:50 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/09 19:54:52 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string cases[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    
    void (Harl::*f[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++) {
        if (cases[i] == level)
        {
            (this->*f[i])();
            break ;
        }
    }
}

void Harl::debug()   { std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"; }
void Harl::info()    { std::cout << "I cannot believe Adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"; }
void Harl::warning() { std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n"; }
void Harl::error()   { std::cout << "This is unacceptable! I want to speak to the manager now.\n"; }

