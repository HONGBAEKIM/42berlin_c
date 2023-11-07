/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/07 11:58:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
    //Default constructor called
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &_fixed)
{
    //Copy constructor called
    //getRawBits member function called
    std::cout << "Copy constructor called" << std::endl;
    this->value = _fixed.getRawBits();
}

int Fixed::getRawBits(void) const
{
    //getRawBits member function called
    //0
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

Fixed& Fixed::operator=(const Fixed &_fixed)
{
    //Copy assignment operator called
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &_fixed)
        this->value = _fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    //Destructor called
    std::cout << "Destructor called" << std::endl;
    value = 0;
}

/* 

Fixed a;
std::cout << a.getRawBits() << std::endl;


    Default constructor called
Copy constructor called
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
    getRawBits member function called
    0
getRawBits member function called
0
getRawBits member function called
0
    Destructor called
Destructor called
Destructor called 
*/

/*
Fixed a;
Fixed b( a );

std::cout << a.getRawBits() << std::endl;

    Default constructor called
    Copy constructor called
getRawBits member function called
Default constructor called
Copy assignment operator called
    getRawBits member function called
    getRawBits member function called
    0
getRawBits member function called
0
getRawBits member function called
0
    Destructor called
    Destructor called
Destructor called 
  
*/

/* 

Fixed a;
Fixed b( a );

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;



    Default constructor called
    Copy constructor called
getRawBits member function called
Default constructor called
Copy assignment operator called
    getRawBits member function called
    getRawBits member function called
    0
    getRawBits member function called
    0
getRawBits member function called
0
    Destructor called
    Destructor called
Destructor called 
*/

/* 
Fixed a;
Fixed b( a );

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;

    Default constructor called
    Copy constructor called
getRawBits member function called
Default constructor called
Copy assignment operator called
    getRawBits member function called
    getRawBits member function called
    0
    getRawBits member function called
    0
getRawBits member function called
0
    Destructor called
    Destructor called
Destructor called 
*/

/* 

Fixed a;
Fixed b( a );
Fixed c;

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;

    
    Default constructor called
    Copy constructor called
    getRawBits member function called
    Default constructor called
Copy assignment operator called
    getRawBits member function called
    
    getRawBits member function called
    0
    getRawBits member function called
    0
    getRawBits member function called
    0
    Destructor called
    Destructor called
    Destructor called 
*/
