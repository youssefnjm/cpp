/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:31:48 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/14 19:55:13 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

int Fixed::getRawBits( void ) const { 
    std::cout << "getRawBits member function callsed" << std::endl;
    return rawBits;
};

void Fixed::setRawBits( int const raw ) { rawBits = raw; };

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
};

Fixed::Fixed(const int val) {
    std::cout << "Int constructor called" << std::endl;
    int tmp = val * (1 << fractionalBits);
    setRawBits(tmp);
};

Fixed::Fixed(const float val) {
    std::cout << "Float constructor called" << std::endl;
    int tmp = roundf(val * (1 << fractionalBits));
    setRawBits(tmp);
};

Fixed::Fixed(Fixed const &obj) {
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(obj.getRawBits());
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

float Fixed::toFloat( void ) const {
    return (float)rawBits / (1 << fractionalBits);
};

int Fixed::toInt( void ) const {
    return rawBits / (1 << fractionalBits);
};

Fixed& Fixed::operator = (const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        setRawBits(other.getRawBits());
    }
    return *this;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
};
