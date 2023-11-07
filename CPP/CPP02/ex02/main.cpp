/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:51 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/07 17:14:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    //0
    std::cout << a << std::endl;
    
    //0.00390625 which is 1/256 (2^-8)
    std::cout << ++a << std::endl;
    
    //0.00390625 which is 1/256 (2^-8)
    std::cout << a << std::endl;
    
    //0.00390625 which is 1/256 (2^-8)
    std::cout << a++ << std::endl;
    
    //0.0078125 which is 2/256 (2^-8)
    std::cout << a << std::endl;

    //10.1016 = 10.10 + 0.0016
    
    //10.10 = 5.05 * 2

    //0.0016 = (((5.05 * 16) * (2 * 16)) / 16) / 100000 =0.001616
    //5.05 * 16 = 80.8 which is represented as 80.8 with 4 fractioal bits.
    //2 * 16 = 32 which is represented as 32 with 4 fractioal bits.
    //Multiply these fixed-point values: 80.8 * 32 = 2585.6
    //To get the fractional part, divide by the scaling factor: 2585.6 / 16 = 161.6
    //Finally, convert the result to a floating-point value: 161.6 / 100000 = 0.001616
    std::cout << b << std::endl;

    
    std::cout << Fixed::max( a, b ) << std::endl;

    // Fixed c = 3;
    // std::cout << Fixed::min( c, a ) << std::endl;
    

    return 0;
}
