/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/12 19:11:47 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

# define MAX_CONTACTS 8

class Phonebook
{
    public:
        Phonebook();
        ~Phonebook();
        void    addContact();
        void    searchContact();

    private:
        Contact _contacts[MAX_CONTACTS];
        int     _contact_index;
};

#endif