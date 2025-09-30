/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:36:55 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/27 15:36:58 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	std::string choice;
	PhoneBook phonebook;

	while (1)
	{
		choice = phonebook.ft_getline("what action you want (ADD, SEARCH, EXIT): ");
		if (choice == "ADD")
			phonebook.add();
		else if (choice == "SEARCH")
			phonebook.search();
		else if (choice == "EXIT")
			return (0);
		else
			std::cout << "\033[31m" << "incorrect action" << "\033[0m" << std::endl;
	}
	return (0);
}
