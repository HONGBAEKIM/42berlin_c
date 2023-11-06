/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:51 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/06 16:15:50 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    //Default constructor called
    Fixed a;
    
    //Copy constructor called
    Fixed b( a );
    
    //Default constructor called
    Fixed c;

    //Copy assignment operator called
    c = b;

    //getRawBits member function called
    //0
    std::cout << a.getRawBits() << std::endl;

    //getRawBits member function called
    //0
    std::cout << b.getRawBits() << std::endl;
    
    //getRawBits member function called
    //0
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}
