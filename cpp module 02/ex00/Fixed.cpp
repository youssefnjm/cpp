/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:47:14 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/07 16:52:00 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// const int fractionalBits = 8;

int Fixed::getRawBits( void ) const { 
    std::cout << "getRawBits member function callsed" << std::endl;
    return integer; 
};

void Fixed::setRawBits( int const raw ) { 
    integer = raw;
};
        
Fixed::Fixed() {
    setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed const &obj){
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(obj.getRawBits());
};

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        setRawBits(other.getRawBits());
    }
    return *this;
};
    
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};