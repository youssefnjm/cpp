/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:36:55 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/06 10:15:56 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string Choice;
	PhoneBook PhoneBook;

	while (1)
	{
		Choice = PhoneBook.FtGetline("what action you want (ADD, SEARCH, EXIT): ");
		if (Choice == "ADD")
			PhoneBook.Add();
		else if (Choice == "SEARCH")
			PhoneBook.Search();
		else if (Choice == "EXIT")
			return (0);
		else
			std::cout << "\033[31m" << "incorrect action" << "\033[0m" << std::endl;
	}
	return (0);
}
