/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:48 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/20 15:30:52 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//calling when an object of the class is created
Contact::Contact() {}

//calling when an object of the class is destroyed
Contact::~Contact() {}


//set
void    Contact::SaveContact(std::string firstname,\
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
std::string Contact::GetFirstName(void)
{
    return (this->_first_name);
}

std::string Contact::GetLastName(void)
{
    return (this->_lastname);
}

std::string Contact::GetNickName(void)
{
    return (this->_nickname);
}

//public
void    Contact::PrintDetails(void)
{
    std::cout << "first name:              " << this->_firstname;
    std::cout << "last name:               " << this->_lastname;
    std::cout << "nickname:                " << this->_nickname;
    std::cout << "Phone number:            " << this->_phonenumber;
    std::cout << "Darkest Secret:          " << this->_darkestsecret;
}