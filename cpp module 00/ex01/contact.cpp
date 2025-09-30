/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:37:07 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/09/27 15:37:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./contact.hpp"

void Contact::setFirstName(std::string fn) { fname = fn; }
void Contact::setLastName(std::string ln) { lname = ln; }
void Contact::setNickname(std::string nn) { nickname = nn; }
void Contact::setPhoneNumber(std::string pn) { phone_number = pn; }
void Contact::setSecret(std::string s) { secret = s; }

std::string Contact::getFirstName() const { return fname; }
std::string Contact::getLastName() const { return lname; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getSecret() const { return secret; }