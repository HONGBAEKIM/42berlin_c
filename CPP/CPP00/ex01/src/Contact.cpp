/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:48 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/20 15:30:52 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//calling when an object of the class is created
Contact::Contact(void) {}

//calling when an object of the class is destroyed
Contact::~Contact(void) {}


//set
void    Contact::saveContact(std::string firstname,\
                            std::string lastname,\
                            std::string nickname,\
                            std::string phoneNumber,\
                            std::string darkestSecret)
{
    this->_firstname = firstname;
    this->_lastname = lastname;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumber;
    this->_darkestSecret = darkestSecret;
}
                            

//private
std::string Contact::getFirstName(void)
{
    return (this->_firstname);
}

std::string Contact::getLastName(void)
{
    return (this->_lastname);
}

std::string Contact::getNickName(void)
{
    return (this->_nickname);
}

//public
void    Contact::printDetails(void)
{
    std::cout << "First name:              " << this->_firstname << std::endl;
    std::cout << "Last name:               " << this->_lastname << std::endl;
    std::cout << "Nickname:                " << this->_nickname << std::endl;
    std::cout << "Phone number:            " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret:          " << this->_darkestSecret << std::endl;
}