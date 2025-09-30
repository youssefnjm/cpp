/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:34 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/27 15:37:35 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./phonebook.hpp"

PhoneBook::PhoneBook() : current_pos(0), filled_contact(0) {}
PhoneBook::~PhoneBook() {}

int PhoneBook::is_all_digit(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

std::string PhoneBook::telephone_parser(std::string msg)
{
	std::string buffer;

	while (1)
	{
		buffer = ft_getline(msg);
		if (is_all_digit(buffer))
			break ;
		std::cout << "\033[31m" << "num should containe only numbers" << "\033[0m" << std::endl;
	}
	return (buffer);
}

int PhoneBook::index_parser(std::string msg)
{
	std::string buffer;
	int var = -1;

	while (1)
	{
		buffer = ft_getline(msg);
		if (is_all_digit(buffer))
		{
			var = std::atoi(buffer.c_str());
			if (var >= 0 && var < filled_contact)
				break ;
		}
		std::cout << "\033[31m" << "index should containe only digit and between 0 and " << filled_contact << "\033[0m" << std::endl;
	}
	return (var);
}

int PhoneBook::is_blank_or_unprintable(std::string buffer)
{
	int i = 0;
	int res = 0;

	if (buffer.empty())
		return (0);
	while (buffer[i])
	{
		if (std::isprint(buffer[i]) == 0)
			return (0);
		else if (!std::isspace(buffer[i]))
			res = 1;
		i++;
	}
	return (res);
}

std::string PhoneBook::ft_getline(std::string msg)
{
	std::string buffer;

	while (1)
	{
		std::cout << msg;
		std::getline(std::cin, buffer, '\n');
		if (std::cin.eof())
			exit(1);
		if (is_blank_or_unprintable(buffer))
			break;
		std::cout << "the input should not be blank or containe unprintable charachters" << std::endl;
	}
	return (buffer);
}

void PhoneBook::add()
{
	current_pos = current_pos % 8;

	contact[current_pos].setFirstName(ft_getline("entre first name: "));
	contact[current_pos].setLastName(ft_getline("entre last name: "));
	contact[current_pos].setNickname(ft_getline("entre nickname: "));
	contact[current_pos].setPhoneNumber(telephone_parser("entre phone number: "));
	contact[current_pos].setSecret(ft_getline("entre darkest secret: "));

	current_pos++;
	if (filled_contact < 8)
		filled_contact++;
}

void PhoneBook::print_col(std::string str)
{
	std::string tmp;
	int len;

	len = str.length();
	if (len > 10)
		tmp = str.substr(0, 9) + ".";
	else
	{
		tmp = std::string(10 - len, ' ') + str;
	}
	std::cout << tmp << "|";
}

void PhoneBook::search()
{
	int i = -1;

	print_col("INDEX");
	print_col("FIRST NAME");
	print_col("LAST NAME");
	print_col("NICKNAME");

	std::cout << std::endl << std::string(44, '-') << std::endl;

	while (++i < filled_contact)
	{
		std::cout << "         " << i << "|";
		print_col(contact[i].getFirstName());
		print_col(contact[i].getLastName());
		print_col(contact[i].getNickname());
		std::cout << std::endl;
	}

	if (filled_contact != 0)
	{
		int index = index_parser("entry the index: ");

		std::cout << "first name: " << contact[index].getFirstName() << std::endl;
		std::cout << "lastname: " << contact[index].getLastName() << std::endl;
		std::cout << "nickname: " << contact[index].getNickname() << std::endl;
		std::cout << "phone number: " << contact[index].getPhoneNumber() << std::endl;
		std::cout << "secret: " << contact[index].getSecret() << std::endl;
	}
}
