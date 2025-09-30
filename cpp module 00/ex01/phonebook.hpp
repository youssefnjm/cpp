/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:38 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/27 15:37:39 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

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

		PhoneBook();
		~PhoneBook();
};

#endif