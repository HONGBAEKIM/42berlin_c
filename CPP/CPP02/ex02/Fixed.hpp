/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:25:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/07 15:23:19 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits;
        
    public:
        //Default constructor
        Fixed();
        
        //Int constructor
        Fixed(const int _value);

        //Float constructor
        Fixed(const float _value);

        //Copy constructor
        Fixed(const Fixed &_fixed);
        
        //Copy assignment operator
        Fixed& operator=(const Fixed &_fixed);
        
        //Destructor
        ~Fixed();
        
        bool operator>(const Fixed& _fixed) const;
        bool operator<(const Fixed& _fixed) const;
        bool operator>=(const Fixed& _fixed) const;
        bool operator<=(const Fixed& _fixed) const;
        bool operator==(const Fixed& _fixed) const;
        bool operator!=(const Fixed& _fixed) const;
        
        Fixed operator+(const Fixed& _fixed) const;
        Fixed operator-(const Fixed& _fixed) const;
        Fixed operator*(const Fixed& _fixed) const;
        Fixed operator/(const Fixed& _fixed) const;
        
        Fixed& operator++(void);
        const Fixed operator++(int);
        Fixed& operator--(void);
        const Fixed operator--(int);
        
        int getRawBits( void ) const;
        
        void setRawBits( int const raw );

        float toFloat( void ) const;

        int toInt( void ) const;

        static const Fixed& max(const Fixed& _fixed1, const Fixed& _fixed2);
        static Fixed& max(Fixed& _fixed1, Fixed& _fixed2);
        static const Fixed& min(const Fixed& _fixed1, const Fixed& _fixed2);
        static Fixed& min(Fixed& _fixed1, Fixed& _fixed2);

};

//An overload of the insertion («) operator 
//that inserts a floating-point representation
//of the fixed-point number into the output stream object 
//passed as parameter.
std::ostream& operator<<(std::ostream& out, const Fixed& _fixed);

#endif
