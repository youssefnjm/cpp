/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:34 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/08 13:25:13 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : CurrentPos(0), FilledContact(0) {}
PhoneBook::~PhoneBook() {}

int PhoneBook::IsInt(std::string str, int flag)
{
	int i = 0;
	size_t res = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
		if (flag == 1)
		{
			res = res * 10 + (str[i] - '0');
			if (res > (size_t)2147483647 && res < (size_t)-2147483648)
				return (0);
		}
		i++;
	}
	return (1);
}

std::string PhoneBook::TelephoneParser(std::string msg)
{
	std::string Buffer;

	while (1)
	{
		Buffer = FtGetline(msg);
		if (IsInt(Buffer, 0))
			break ;
		std::cout << "num should containe only numbers" << std::endl;
	}
	return (Buffer);
}

int PhoneBook::IndexParser(std::string msg)
{
	std::string Buffer;
	int var = -1;

	while (1)
	{
		Buffer = FtGetline(msg);
		if (IsInt(Buffer, 1))
		{
			var = std::atoi(Buffer.c_str());
			if (var >= 0 && var < FilledContact)
				break ;
		}
		std::cout <<  "index should containe only digit and between 0 and " << (FilledContact - 1) << std::endl;
	}
	return (var);
}

int PhoneBook::IsBlank(std::string buffer)
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

std::string PhoneBook::FtGetline(std::string msg)
{
	std::string Buffer;

	while (1)
	{
		std::cout << msg;
		std::getline(std::cin, Buffer, '\n');
		if (std::cin.eof())
			exit(1);
		if (IsBlank(Buffer))
			break ;
		std::cout << "the input should not be blank" << std::endl;
	}
	return (Buffer);
}

void PhoneBook::Add()
{
	CurrentPos = CurrentPos % 8;

	Contact[CurrentPos].setFirstName(FtGetline("entre first name: "));
	Contact[CurrentPos].setLastName(FtGetline("entre last name: "));
	Contact[CurrentPos].setNickname(FtGetline("entre Nickname: "));
	Contact[CurrentPos].setPhoneNumber(TelephoneParser("entre phone number: "));
	Contact[CurrentPos].setSecret(FtGetline("entre darkest Secret: "));

	CurrentPos++;
	if (FilledContact < 8)
		FilledContact++;
}

void PhoneBook::PrintCol(std::string str)
{
	std::string Tmp;
	int Len;

	Len = str.length();
	if (Len > 10)
		Tmp = str.substr(0, 9) + ".";
	else
	{
		Tmp = std::string(10 - Len, ' ') + str;
	}
	std::cout << Tmp << "|";
}

void PhoneBook::Search()
{
	int i = -1;
	if (FilledContact != 0)
	{
		PrintCol("INDEX");
		PrintCol("FIRST NAME");
		PrintCol("LAST NAME");
		PrintCol("Nickname");

		std::cout << std::endl << std::string(44, '-') << std::endl;

		while (++i < FilledContact)
		{
			std::cout << "         " << i << "|";
			PrintCol(Contact[i].getFirstName());
			PrintCol(Contact[i].getLastName());
			PrintCol(Contact[i].getNickname());
			std::cout << std::endl;
		}

		int Index = IndexParser("entry the index: ");

		std::cout << "First name: " << Contact[Index].getFirstName() << std::endl;
		std::cout << "Last name: " << Contact[Index].getLastName() << std::endl;
		std::cout << "Nickname: " << Contact[Index].getNickname() << std::endl;
		std::cout << "Phone Number: " << Contact[Index].getPhoneNumber() << std::endl;
		std::cout << "Secret: " << Contact[Index].getSecret() << std::endl;
	}
}
