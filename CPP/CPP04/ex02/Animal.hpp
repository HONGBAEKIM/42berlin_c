/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 11:01:41 by hongbaki         ###   ########.fr       */
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
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &_Animal);
        Animal& operator=(const Animal &_Animal);
        //with virtual, derived classes are called when deleting an object.
        virtual ~Animal(void);  

        //Abstract class
        //1)Pure virtual functions
        //Added '= 0' at the end
        //It has no implementation in the base class and must be implemented
        //by any concrete (i.e., non-abstract) derived class.
        
        //2)Can not be instantiated
        //Since abstract classes have pure virtual functions without implementations, 
        //they cannot be instantiated on their own.

        //3)Derived class implementation
        //Any class derived from an abstract class must provide implementations 
        //for all the pure virtual functions declared in the abstract class. 
        //Otherwise, the derived class will also be considered abstract 
        //and cannot be instantiated.
        
        //and comment out 'makeSound' function from animal.cpp
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif
