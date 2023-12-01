/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:27:38 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/01 14:23:42 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVRTER_HPP
# define SCALARCONVRTER_HPP

#include "Helpers.hpp"

#include <iostream> //input, output streams.
#include <cstdlib> //malloc, free, rand, and exit
#include <cerrno> //errno
#include <limits> //numeric_limits
#include <cstring> //strlen
#include <string> //std::string
#include <cmath> //floor



class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);

    public:
        ~ScalarConverter();
        ScalarConverter& operator=(ScalarConverter const &src);

        static void printInt(int i);
		static void printChar(char c);
		static void printSpecial(const std::string &val);
		static void printFloat(float f);
		static void printDouble(double d);
		static void convert(const std::string &val);

        class InvalidInputException : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("Invalid input");
                }
        };
};

#endif
