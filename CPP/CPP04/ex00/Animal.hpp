/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 10:24:18 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

//we are studying virtual function in CPP04.
//Virtual functions allow up to override methods in subclasses

//Class Dog and Cat inherit from Class aminal
/*     
        Animal

        /    \

       Dog  Cat 
*/

//With virtual fucntion

//1)Polymorphism 
// Polymorphism enables objects of different classes 
// to be treated as objects of a common base class, allowing 
// for more generic and flexible code

//2)dynamic binding
// ensures that the appropriate function is called 
// at runtime based on the actual type of the object, 
// allowing for polymorphic behavior in object-oriented programming.

class Animal
{
    //when you use protected instead of private at main class Animal
    //derived class(cat and dog) do not need to declear private member variable
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &_Animal);
        Animal& operator=(const Animal &_Animal);
        //with virtual, derived classes are called when deleting an object.
        virtual ~Animal(void);  

        virtual void makeSound() const;
        std::string getType() const;
};

#endif
