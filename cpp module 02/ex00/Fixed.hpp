/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:47:23 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/11 18:11:03 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int integer;
        static const int fractionalBits;
    public:
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        Fixed();
        Fixed(Fixed const &obj);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

};

#endif