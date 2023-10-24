/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:52 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/12 19:11:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//Initialize
Phonebook::Phonebook(void)
{
    _contact_index = 0;
}

//Empty
Phonebook::~Phonebook(void)
{
}

//Save user input
static void get_data(std::string &data)
{
    if (std::getline(std::cin, data).eof())
    {
        std::cout << std::endl;
        std::exit(0);
    }
}

//print
static void displayTable(Contact contacts[MAX_CONTACTS])
{
    std::cout << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "    Index[First Name | Last Name | Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        //if i is shorter than 10 characters, it will be added with spaces 
        //on the left side to make it 10 characters wide
        std::cout << std::setw(10) << std::right << i << "|";
        if (contacts[i].getFirstName().length() > 10)
            std::cout << contacts[i].getFirstName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
        if (contacts[i].getLastName().length() > 10)
            std::cout << contacts[i].getLastName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contacts[i].getLastName() << "|";
        if (contacts[i].getNickName().length() > 10)
            std::cout << contacts[i].getNickName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contacts[i].getNickName() << "|" << std::endl;
    }
}


//public
//Get user input and store them into the Contact class

void Phonebook::addContact(void)
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    while(1)
    {
        std::cout << "Enter first name: ";
        get_data(firstname);
        if (isalpha(firstname[0]) == false)
        {
            std::cout << "Need to start with an alphabet" << std::endl;
            continue ;
        }
        if (firstname.empty() == false)
            break ;
    }

    while(1)
    {
        std::cout << "Enter last name: ";
        get_data(lastname);
        if (isalpha(lastname[0]) == false)
        {
            std::cout << "Need to start with an alphabet" << std::endl;
            continue ;
        }
        if (lastname.empty() == false)
            break ;
    }

    while(1)
    {
        std::cout << "Enter nickname: ";
        get_data(nickname);
        if (isalpha(nickname[0]) == false)
        {
            std::cout << "Need to start with an alphabet" << std::endl;
            continue ;
        }
        if (nickname.empty() == false)
            break ;
    }

    while(1)
    {
        std::cout << "Enter phone number: ";
        get_data(phone_number);
        if (isdigit(phone_number[0]) == false)
        {
            std::cout << "Need to start with a digit" << std::endl;
            continue ;
        }
        if (phone_number.empty() == false)
            break ;
    }

    while(1)
    {
        std::cout << "Enter darkest secret: ";
        get_data(darkest_secret);
        if (darkest_secret.empty() == false)
        {
            if (darkest_secret[0] == 32)
                std::cout << "Need to start with a alphabet or digit" << std::endl;
            else
                break ;
        }
    }

    _contacts[_contact_index].saveContact(firstname, \
		lastname, nickname, phone_number, darkest_secret);
    _contact_index = (_contact_index + 1) % MAX_CONTACTS;
}

//search
void    Phonebook::searchContact(void)
{
    std::string index;

    if (_contact_index == 0)
    {
        std::cout << "ADD a contact" << std::endl;
        return ;
    }
    displayTable(_contacts);
    while (1)
    {
        std::cout << "Enter search index (0-7): ";
        get_data(index);
        if (index.length() == 1 && '0' <= index[0] && index[0] <= '7')
        {
            if (_contacts[index[0] - '0'].getFirstName().empty() == true)
            {
                std::cout << "Invalid index" << std::endl;
                continue ;
            }
            else
            {
                _contacts[index[0] - '0'].printDetails();
                break ;
            }
        }
        else
            std::cout << "Invalid index" << std::endl;
    }
}
