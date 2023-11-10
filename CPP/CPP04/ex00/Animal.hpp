/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 13:41:17 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

//we are studying virtual function from CPP04.
//Virtual functions allow up to override methods in subclasses

//So here!
//Class aminal, and class cat, class dog.
//Class aminal is derived by class cat and class dog.

//Class Animal is intecded to be inherited by derived classes
//which are cat and dog. 
class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &_Animal);
        Animal& operator=(const Animal &_Animal);
        virtual ~Animal(void);

        virtual void makeSound() const;
        std::string getType() const;
};

#endif
