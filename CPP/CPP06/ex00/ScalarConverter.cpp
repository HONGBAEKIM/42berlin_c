/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:27:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 11:54:02 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}


ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (*this) = src;
}
        
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void) src;
    return (*this);
}

/* 
What does 'cast' means?
-converting a value frome one data type to another.

What is 'static_cast'? 
1. Convert between primitive types like int to float or double to int
2. Convert pointer types such as char* to void*.
3. Conversion between related classes, such as base class pointer to derived class pointer. 
*/

void ScalarConverter::printInt(int i)
{
    //integer to char
    char c = static_cast<char>(i);
    //integer to float
    float f = static_cast<float>(i);
    //integer to double
    double d = static_cast<double>(i);

    std::cout << "char: " << (i > 127 || i < 0 ? "impossible"
            : (std::isprint(i) ? "'" + std::string(1, c) + "'" : "Non displayable"))
            << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void ScalarConverter::printChar(char c)
{
    int i = static_cast<char>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
            : (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
            << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void ScalarConverter::printSpecial(const std::string &val)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << val << (val == "nanf" || val == "-inff" || val == "+inff" ? "" : "f") << std::endl;
    std::cout << "double: " << (val == "nanf" ? "nan" : val) << std::endl;
}

/* 
float: Single Precision, 32-bit floating point format. 7 decimal digits for precision.
double: Double Precision, 64-bit floating point format. 15 decimal digits for precision.
*/

void ScalarConverter::printFloat(float f)
{
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
            : (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
            << std::endl;
    //'f' cast to an integer without causing underflow or overflow 
    if (std::numeric_limits<int>::min() <= f && f <= std::numeric_limits<int>::max())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    //'d' cast to single-precision float without causing underflow or overflow 
    if (std::numeric_limits<float>::min() <= d && d <= std::numeric_limits<float>::max())
        std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    //'d' is within the range of the doule.
    if (std::numeric_limits<double>::min() <= d && d <= std::numeric_limits<double>::max())
        std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
            : (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
            << std::endl;
    if (std::numeric_limits<int>::min() <= d && d <= std::numeric_limits<int>::max())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (std::numeric_limits<float>::min() <= d && d <= std::numeric_limits<float>::max())
        std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    if (std::numeric_limits<double>::min() <= d && d <= std::numeric_limits<double>::max())
        std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &val)
{
    if (val.size() == 0)
        throw ScalarConverter::InvalidInputException();
    else if (val.size() == 1)
    {
        if (std::isdigit(val[0]))
        {
            //c_str() is called on the val object
            //std::string val
            int d = std::atoi(val.c_str());
            ScalarConverter::printInt(d);
        }
        else
            ScalarConverter::printChar(val[0]);
    }
    else if (isSpecial(val))
        ScalarConverter::printSpecial(val);
    else
    {
        if (isFloat(val))
        {
            float f = std::atof(val.c_str());
            ScalarConverter::printFloat(f);
        }
        else if (isDouble(val))
        {
            char *endPtr;
            //str 'val' to a double
            float d = strtod(val.c_str(), &endPtr);
            //when the entire string was successfully converted
            if (*endPtr == '\0')
                ScalarConverter::printDouble(d);
            else
                throw ScalarConverter::InvalidInputException();  
        }
        else if (isInteger(val))
        {
            int d = std::atoi(val.c_str());
            ScalarConverter::printInt(d);
        }
        else
            throw ScalarConverter::InvalidInputException();

    }
}
/* 
char const *ScalarConverter::InvalidInputException::what() const throw()
{
    return ("Invalid input");
} */

