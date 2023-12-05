/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:29:18 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/05 13:59:24 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Helpers.hpp"

bool isSpecial(std::string const &val)
{
    return (val == "nan" || val == "nanf" || val == "-inff" || val == "+inff" || val == "-inf" || val == "+inf");
}

bool isrealDigit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    //example 1.23e3 or 1.23E3 is equivalent to 1.23 x 10^3, which is 1230.
    //example 1.23e-3 or 1.23E-3 is equivalent to 1.23 x 10^-3, which is 0.00123 
    if (c == '+' || c == 'E' || c == 'e')
        return (1);
    return (0);
}

bool isFloat(std::string const &val)
{
    int d = 0;
    for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.length(); i++)
    {
        if (d == 0 && isrealDigit(val[i]))
            d = 1;
        else if (d == 0 && !isrealDigit(val[i]))
            return (0);
        else if (d == 1 && val[i] == '.')
            d = 2;
        else if (d == 1 && val[i] != '.' && !isrealDigit(val[i]))
            return (0);
        else if (d == 2 && isrealDigit(val[i]))
            d = 3;
        else if ((d == 2 || d == 3) && !isrealDigit(val[i]) && val[i] != 'f')
            return (0);
        else if (d == 3 && val[i] == 'f')
            d = 4;
    }
    //when d = 4 is true otherwise false
    return (d == 4);
}

bool isDouble(std::string const &val)
{
    int d = 0;
    for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.length(); i++)
    {
        if (d == 0 && isrealDigit(val[i]))
            d = 1;
        else if (d == 0 && !isrealDigit(val[i]))
               return (0);
        else if (d == 1 && val[i] == '.')
               d = 2;
        else if (d == 1 && val[i] != '.' && !isrealDigit(val[i]))
               return (0);
        else if (d == 2 && isrealDigit(val[i]))
              d = 3;
        else if ((d == 2 || d == 3) && !isrealDigit(val[i]))
            return (0);
    }
    return (d == 3);
}

bool isInteger(std::string const &val)
{
    for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.length(); i++)
        if (!std::isdigit(val[i]))
            return (0);
    return (1);
}
