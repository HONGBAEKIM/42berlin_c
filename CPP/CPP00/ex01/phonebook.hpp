/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:11:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/26 11:48:34 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

# define MAX_CONTACTS 8

class Phonebook
{
    //Public are accessible from outside the class
    public:
        //it is called when an object of the class is created.
        Phonebook();
        //It iss called when an object of the class is destroyed 
        //or goes out of scope.
        ~Phonebook();
        void    addContact();
        void    searchContact();
    
    //Private are only accessible from within the class itself.
    private:
        Contact _contacts[MAX_CONTACTS];
        int     _contact_index;
};

#endif
