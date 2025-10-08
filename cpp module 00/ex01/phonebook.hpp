/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:38 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/08 12:38:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact Contact[8];
		int CurrentPos;
		int FilledContact;

		void PrintCol(std::string str);
		std::string TelephoneParser(std::string msg);
		int IndexParser(std::string msg);
		int IsInt(std::string str, int flag);
		int IsBlank(std::string buffer);


	public:
		std::string FtGetline(std::string msg);
		void Add();
		void Search();

		PhoneBook();
		~PhoneBook();
};

#endif