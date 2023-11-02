/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 14:56:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//std::cout, std::endl
#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    //address
    std::cout << &string << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    //value
    std::cout << string << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}
