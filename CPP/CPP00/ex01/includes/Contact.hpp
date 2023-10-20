/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:44 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/20 15:46:56 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
//std::cout, std::endl
# include <iostream>
# include <string>
//std::setw
# include <iomanip>
//isalpha
# include <cctype>

class Contact
{
    public:
        Contact();
        ~Contact();
        void    SaveContact(std::string firstname,\
                            std::string lastname,\
                            std::string nickname,\
                            std::string phoneNumber,\
                            std::string darkestSecret);
        void    PrintDetails();
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();

    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecrett;
};

#endif