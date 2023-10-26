/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:44 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/26 14:33:09 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

//std::cout, std::endl
# include <iostream>

//std::setw
# include <iomanip>

//isalpha
# include <cctype>

//for std::exit
#include <cstdlib>

class Contact
{
    public:
        Contact();
        ~Contact();
        void    saveContact(std::string firstname,\
                            std::string lastname,\
                            std::string nickname,\
                            std::string phone_number,\
                            std::string darkest_secret);
        void    printDetails();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();

    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
};

#endif
