/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:34 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/06 10:19:54 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : CurrentPos(0), FilledContact(0) {}
PhoneBook::~PhoneBook() {}

int PhoneBook::IsAllDigit(std::string str)
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

std::string PhoneBook::TelephoneParser(std::string msg)
{
	std::string Buffer;

	while (1)
	{
		Buffer = FtGetline(msg);
		if (IsAllDigit(Buffer))
			break ;
		std::cout << "\033[31m" << "num should containe only numbers" << "\033[0m" << std::endl;
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
		if (IsAllDigit(Buffer))
		{
			var = std::atoi(Buffer.c_str());
			if (var >= 0 && var < FilledContact)
				break ;
		}
		std::cout << "\033[31m" << "index should containe only digit and between 0 and " << FilledContact << "\033[0m" << std::endl;
	}
	return (var);
}

int PhoneBook::IsBlankOrUnprintable(std::string buffer)
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
		if (IsBlankOrUnprintable(Buffer))
			break;
		std::cout << "the input should not be blank or containe unprintable charachters" << std::endl;
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

	if (FilledContact != 0)
	{
		int Index = IndexParser("entry the index: ");

		std::cout << "first name: " << Contact[Index].getFirstName() << std::endl;
		std::cout << "lastname: " << Contact[Index].getLastName() << std::endl;
		std::cout << "Nickname: " << Contact[Index].getNickname() << std::endl;
		std::cout << "phone number: " << Contact[Index].getPhoneNumber() << std::endl;
		std::cout << "Secret: " << Contact[Index].getSecret() << std::endl;
	}
}
