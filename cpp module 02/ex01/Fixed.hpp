/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:31:30 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/14 17:35:24 by ynoujoum         ###   ########.fr       */
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

};
std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif