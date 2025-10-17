/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:31:30 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/14 18:12:14 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int rawBits;
        static const int fractionalBits;
    public:
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed();
        Fixed(Fixed const &obj);
        Fixed(const int val);
        Fixed(float val);
        ~Fixed();

        Fixed& operator = (const Fixed& other);
        
        Fixed operator ++ (int);
        Fixed& operator ++ ();
        Fixed operator -- (int);
        Fixed& operator -- ();

        bool operator > (const Fixed& other) const;
        bool operator < (const Fixed& other) const;
        bool operator >= (const Fixed& other) const;
        bool operator <= (const Fixed& other) const;
        bool operator == (const Fixed& other) const;
        bool operator != (const Fixed& other) const;

        Fixed operator + (const Fixed& other);
        Fixed operator - (const Fixed& other);
        Fixed operator * (const Fixed& other);
        Fixed operator / (const Fixed& other);

        static const Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);

};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif