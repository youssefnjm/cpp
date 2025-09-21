
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cctype>

class Contact{
	public:
		std::string fname;
		std::string lname;
		std::string nickname;
		std::string phone_number;
		std::string secret;
};

class PhoneBook{
	private:
		int current_pos;
		int filled_contact;
		void print_col(std::string str);
		std::string telephone_parser(std::string msg);
		int index_parser(std::string msg);
		int is_all_digit(std::string str);
		int is_blank_or_unprintable(std::string buffer);
	public:
		Contact contact[8];
		std::string ft_getline(std::string msg);
		void add();
		void search();
};


#endif