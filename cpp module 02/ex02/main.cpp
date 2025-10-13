/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:31:37 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/13 16:41:31 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a ( 4 );
    Fixed const b( 0.5f );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "max: " << Fixed::max( a, b ) << std::endl;
    std::cout << "mix: " << Fixed::min( a, b ) << std::endl;
    
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    
    std::cout << a << " == " << b << " = " << (a == b) << std::endl;
    std::cout << a << " != " << b << " = " << (a != b) << std::endl;
    std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
    std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
    std::cout << a << " < " << b << " = " << (a < b) << std::endl;
    std::cout << a << " > " << b << " = " << (a > b) << std::endl;
    
    return 0;
}