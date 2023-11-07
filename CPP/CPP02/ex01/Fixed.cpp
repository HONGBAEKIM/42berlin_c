/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/07 11:57:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
    //Default constructor called
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int _value)
{
    //Int constructor called
    std::cout << "Int constructor called" << std::endl;
    this->value = (_value << this->bits);
}

Fixed::Fixed(const float _value)
{
    //Float constructor called
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(_value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &_fixed)
{
    //Copy constructor called
    std::cout << "Copy constructor called" << std::endl;
    this->value = _fixed.getRawBits();
}

int Fixed::getRawBits( void ) const
{
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float Fixed::toFloat( void ) const
{
    //(1 << this->bits)
    //is calculates a scaling factor in powers of 2
    return ((float)this->value / (1 << this->bits));
}

int Fixed::toInt( void ) const
{
    return (this->value >> this->bits);
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
    this->value = 0;
}


std::ostream& operator<<(std::ostream& out, const Fixed& _fixed)
{
    //Insert the '_fixed.toFloat()' representation into the output 'out'
    out << _fixed.toFloat();
    return (out);
}
