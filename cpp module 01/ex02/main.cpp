/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:00:06 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/06 22:22:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main()
{
    std::string msg = "HI THIS IS BRAIN";
    
    std::string *stringPTR = &msg;
    std::string& stringREF = msg;
    
    std::cout << "The memory Address of the variable:   " << &msg << std::endl;
    std::cout << "The memory Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory Address held by stringREF: " << &stringREF << std::endl;

    std::cout << "The value the string variable:     " << msg << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    
    return (0);
}