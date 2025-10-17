/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:31:48 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/15 08:11:44 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

int Fixed::getRawBits( void ) const { 
    return rawBits;
};

void Fixed::setRawBits( int const raw ) { 
    rawBits = raw;
};

Fixed::Fixed() {
    setRawBits(0);
};

Fixed::Fixed(const int val) {
    int tmp = val << fractionalBits;
    setRawBits(tmp);
};

Fixed::Fixed(float val) {
    int tmp = roundf(val * (1 << fractionalBits));
    setRawBits(tmp);
};
        
Fixed::Fixed(Fixed const &obj) {
    setRawBits(obj.getRawBits());
};
    
Fixed::~Fixed() {};

Fixed& Fixed::operator = (const Fixed& other) {
    if (this != &other) {
        setRawBits(other.getRawBits());
    }
    return *this;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
};

float Fixed::toFloat( void ) const {
    return (float)rawBits / (1 << fractionalBits);
};

int Fixed::toInt( void ) const {
    return rawBits >> fractionalBits;
};

// -------  increment/decrement
Fixed Fixed::operator ++ (int) {
    Fixed before(*this);
    setRawBits(getRawBits() + 1);
    return before;
};

Fixed& Fixed::operator ++ () {
    setRawBits(getRawBits() + 1);
    return *this;
};

Fixed Fixed::operator -- (int) {
    Fixed before(*this);
    setRawBits(getRawBits() - 1);
    return before;
};

Fixed& Fixed::operator -- () {
    setRawBits(getRawBits() - 1);
    return *this;
};

// ------- comparison operators
bool Fixed::operator > (const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
};

bool Fixed::operator >= (const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
};

bool Fixed::operator < (const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
};

bool Fixed::operator <= (const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
};

bool Fixed::operator == (const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
};

bool Fixed::operator != (const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
};

// ------- arithmetic operators
Fixed Fixed::operator + (const Fixed& other) {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return (result);
};

Fixed Fixed::operator - (const Fixed& other) {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return (result);
};

Fixed Fixed::operator * (const Fixed& other) {
    float f = this->toFloat() * other.toFloat();
    Fixed result(f);
    return result;
};

Fixed Fixed::operator / (const Fixed& other) {
    float f = this->toFloat() / other.toFloat();
    Fixed result(f);
    return result;
};

// ------- member functions
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
};

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
};

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
};

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
};
