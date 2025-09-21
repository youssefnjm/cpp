#include "./phonebook.hpp"

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
		std::cout << "\e[1m" << msg << "\e[0m";
		std::getline(std::cin, buffer, '\n');
		if (std::cin.eof())
			exit(1);
		if (is_blank_or_unprintable(buffer))
			break;
		std::cout << "\033[31m" << "the input should not be blank or containe unprintable charachters" << "\033[0m" << std::endl;
	}
	return (buffer);
}



void PhoneBook::add()
{
	current_pos = current_pos % 8;

	contact[current_pos].fname = ft_getline("entre first name: ");
	contact[current_pos].lname = ft_getline("entre last name: ");
	contact[current_pos].nickname = ft_getline("entre nickname: ");
	contact[current_pos].phone_number = telephone_parser("entre phone number: ");
	contact[current_pos].secret = ft_getline("entre darkest secret: ");

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
		print_col(contact[i].fname);
		print_col(contact[i].lname);
		print_col(contact[i].nickname);
		std::cout << std::endl;
	}

	int index = index_parser("entry the index: ");

	std::cout << "         " << index << "|";
	print_col(contact[index].fname);
	print_col(contact[index].lname);
	print_col(contact[index].nickname);

	std::cout << std::endl;
}

int main()
{
	std::string choice;
	PhoneBook phonbook = PhoneBook();

	while (1)
	{
		choice = phonbook.ft_getline("what action you want (ADD, SEARCH, EXIT): ");
		if (choice == "ADD")
			phonbook.add();
		else if (choice == "SEARCH")
			phonbook.search();
		else if (choice == "EXIT")
			return (0);
		else
			std::cout << "\033[31m" << "incorrect action" << "\033[0m" << std::endl;
	}
	return (0);
}
