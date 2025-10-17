/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:47:23 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/15 02:34:56 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int integer;
        static const int fractionalBits = 8;
    public:
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        Fixed();
        Fixed(Fixed const &obj);
        Fixed& operator = (const Fixed& other);
        ~Fixed();

};

#endif