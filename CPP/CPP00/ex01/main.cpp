/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:50 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/26 14:32:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
    std::string userInput;
    Phonebook   phonebook;
    
    while (1)
    {
        //same as 'printf("Enter a command (ADD/SEARCH/EXIT): ")'
        std::cout << "Enter a command (ADD/SEARCH/EXIT): ";
        //read from keyboard input which is 'std::cin'
        //line of text will be stored at 'userInput'
        getline(std::cin, userInput);
         //check if the end-of-file(EOF) condition has been
        //reached on the standard input stream(std::cin)
        if (std::cin.eof())
            break ;
        if (!userInput.compare("ADD"))
            phonebook.addContact();
        else if (!userInput.compare("SEARCH"))
            phonebook.searchContact();
        else if (!userInput.compare("EXIT"))
            break ;
        else
            std::cout << "Invalid option" << std::endl;
    }
    return (0);
}
