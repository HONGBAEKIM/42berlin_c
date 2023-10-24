/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:50 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/20 15:56:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
    std::string userInput;
    Phonebook   phonebook;
    
    while (1)
    {
        std::cout << "Enter a comman (ADD/SEARCH/EXIT): ";
        getline(std::cin, userInput);
        //check if the end-of-file(EOF) condition has been
        //reached on the standard input stream(std::cin)
        if (std::cin.eof())
            break ;
        if (userInput.compare("ADD") == 0)
            phonebook.addContact();
        else if (userInput.compare("SEARCH") == 0)
            phonebook.searchContact();
        else if (userInput.compare("EXIT") == 0)
            break ;
        else
            std::cout << "Invalid option" << std::endl;
    }
    return (0);
}