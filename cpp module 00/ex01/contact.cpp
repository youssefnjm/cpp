/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:12:13 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/08 13:34:21 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

void Contact::setFirstName(std::string fn) { FirstName = fn; }
void Contact::setLastName(std::string ln) { LastName = ln; }
void Contact::setNickname(std::string nn) { Nickname = nn; }
void Contact::setPhoneNumber(std::string pn) { phoneNumber = pn; }
void Contact::setSecret(std::string s) { Secret = s; }

std::string Contact::getFirstName() const { return FirstName; }
std::string Contact::getLastName() const { return LastName; }
std::string Contact::getNickname() const { return Nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getSecret() const { return Secret; }