/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:20 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/12 19:09:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 

int main(int argc, char **argv)
{
    char    *str;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        for (int i = 1; i < argc; i++)
        {
            str = argv[i];
            while (*str)
                std::cout << (char)toupper(*str++);
        }
    std::cout << std::endl;
    return (0);
}

/* int main(int argc, char **argv)
{
    char    *str;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        for (int i = 1; i < argc; ++i)
        {
            str = argv[i];
            while (*str)
                std::cout << (char)toupper(*str++);
        }
    //new line
    std::cout << std::endl;
    return (0);
} */
