/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/07 17:38:02 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const int _value)
{
    this->value = (_value << this->bits);
}

Fixed::Fixed(const float _value)
{
    this->value = roundf(_value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &_fixed)
{
    this->value = _fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &_fixed)
{
    if (this != &_fixed)
        this->value = _fixed.getRawBits();
    return (*this);
}

//The operator> implementation checks whether
//the current Fixed object is greater than another Fixed object 
//by comparing their raw fixed-point representations
bool Fixed::operator>(const Fixed& _fixed) const
{
	//this->getRawBits() is accessing the raw fixed-point representation of the current Fixed object.
    //_fixed.getRawBits() is accessing the raw fixed-point representation of the Fixed object represented by the _fixed parameter.
    if (this->getRawBits() > _fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed& _fixed) const
{
	if (this->getRawBits() < _fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& _fixed) const
{
	if (this->getRawBits() >= _fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& _fixed) const
{
	if (this->getRawBits() <= _fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& _fixed) const
{
	if (this->getRawBits() == _fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& _fixed) const
{
	if (this->getRawBits() != _fixed.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed& _fixed) const
{
	Fixed result(this->toFloat() + _fixed.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed& _fixed) const
{
	Fixed result(this->toFloat() - _fixed.toFloat());
	return (result);
}
Fixed Fixed::operator*(const Fixed& _fixed) const
{
	Fixed result(this->toFloat() * _fixed.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& _fixed) const
{
	Fixed result(this->toFloat() / _fixed.toFloat());
	return (result);
}

//pre-increment (b = ++a)
Fixed& Fixed::operator++()
{
    ++this->value;
    return (*this);
}

//Post-increment (b = a++)
const Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    ++this->value;
    return (result);
}

Fixed& Fixed::operator--()
{
    --this->value;
    return (*this);
}

const Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    --this->value;
    return (result);
}

Fixed::~Fixed()
{
    this->value = 0;
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
    return ((float)this->value / (1 << this->bits));
}

int Fixed::toInt( void ) const
{
    return (this->value >> this->bits);
}

//The objects are not modified within the function
const Fixed& Fixed::min(const Fixed& _fixed1, const Fixed& _fixed2)
{
	//std::cout << "min1" << std::endl;
    if ((_fixed1 < _fixed2) == true)
		return (_fixed1);
	else
		return (_fixed2);
}

//comparing the actual fixed-point values stored within the Fixed objects
//ather than relying on the default comparison operators (<, >, ==, etc.),
//Allows for potential modification of the objects
Fixed& Fixed::min(Fixed& _fixed1, Fixed& _fixed2)
{
	//std::cout << "min2" << std::endl;
    if (_fixed1.getRawBits() < _fixed2.getRawBits())
		return (_fixed1);
	else
		return (_fixed2);
}

const Fixed& Fixed::max(const Fixed& _fixed1, const Fixed& _fixed2)
{
    //std::cout << "max1" << std::endl;
    if ((_fixed1 > _fixed2) == true)
		return (_fixed1);
	else
		return (_fixed2);
}

Fixed& Fixed::max(Fixed& _fixed1, Fixed& _fixed2)
{
    //std::cout << "max2" << std::endl;
    if (_fixed1.getRawBits() > _fixed2.getRawBits())
		return (_fixed1);
	else
		return (_fixed2);
}

std::ostream& operator<<(std::ostream& out, const Fixed& _fixed)
{
    //Insert the '_fixed.toFloat()' representation into the output 'out'
    out << _fixed.toFloat();
    return (out);
}
