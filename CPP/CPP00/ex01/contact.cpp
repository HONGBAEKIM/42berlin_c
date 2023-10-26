/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:48 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/26 13:45:37 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//calling when an object of the class is created
Contact::Contact() {}

//calling when an object of the class is destroyed
Contact::~Contact() {}


//Initialiization in the saveContact
void    Contact::saveContact(std::string firstname,\
                            std::string lastname,\
                            std::string nickname,\
                            std::string phoneNumber,\
                            std::string darkestSecret)
{
    _firstname = firstname;
    _lastname = lastname;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}
                            

//private
std::string Contact::getFirstName()
{
    return (_firstname);
}

std::string Contact::getLastName()
{
    return (_lastname);
}

std::string Contact::getNickName()
{
    return (_nickname);
}

//public
void    Contact::printDetails()
{
    std::cout << "First name:              " << _firstname << std::endl;
    std::cout << "Last name:               " << _lastname << std::endl;
    std::cout << "Nickname:                " << _nickname << std::endl;
    std::cout << "Phone number:            " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret:          " << _darkestSecret << std::endl;
}


/* 
this : pointer that is automatically available in the member functions of a class. 
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
std::string Contact::getFirstName()
{
   return (this->_firstname);
}

std::string Contact::getLastName()
{
   return (this->_lastname);
}

std::string Contact::getNickName()
{
    return (this->_nickname);

}

//public
void    Contact::printDetails()
{
    std::cout << "First name:              " << this->_firstname << std::endl;
    std::cout << "Last name:               " << this->_lastname << std::endl;
    std::cout << "Nickname:                " << this->_nickname << std::endl;
    std::cout << "Phone number:            " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret:          " << this->_darkestSecret << std::endl;
    

} 
*/
