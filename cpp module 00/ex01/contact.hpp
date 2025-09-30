/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:17 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/27 15:37:18 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact {
	private:
		std::string fname;
		std::string lname;
		std::string nickname;
		std::string phone_number;
		std::string secret;

	public:
		void setFirstName(std::string fn);
		void setLastName(std::string ln);
		void setNickname(std::string nn);
		void setPhoneNumber(std::string pn);
		void setSecret(std::string s);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getSecret() const;
};


#endif