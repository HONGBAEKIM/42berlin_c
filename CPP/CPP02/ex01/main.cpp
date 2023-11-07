/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:51 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/07 11:57:36 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    //Default constructor called
    Fixed a;
    
    //Int constructor called
    Fixed const b( 10 );
    
    //Float constructor called
    Fixed const c( 42.42f );
    
    //Copy constructor called
    Fixed const d( b );

    //Float constructor called
    //Copy assignment operator called
    a = Fixed( 1234.4321f );
    //Destructor called

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    // a is 1234.43
    // b is 10
    // c is 42.4219
    // d is 10

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    // a is 1234 as integer
    // b is 10 as integer
    // c is 42 as integer
    // d is 10 as integer

    //Destructor called
    //Destructor called
    //Destructor called
    //Destructor called
    return 0;
}
