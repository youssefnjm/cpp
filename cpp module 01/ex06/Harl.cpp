/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:45:03 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/06 22:22:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()   { std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"; }
void Harl::info()    { std::cout << "I cannot believe Adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"; }
void Harl::warning() { std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n"; }
void Harl::error()   { std::cout << "This is unacceptable! I want to speak to the manager now.\n"; }

