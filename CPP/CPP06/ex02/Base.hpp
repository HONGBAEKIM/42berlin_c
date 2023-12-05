/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:04:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/05 14:00:26 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream> //input, output streams.
#include <cstdlib> //std::srand()
#include <ctime> //std::time(0)
#include <exception>




//Implement a Base class that has a public virtual destructor only
// Create three empty classes A, B and C, that publicly inherit from Base.
class Base
{
    public:
        virtual ~Base();
};

//It randomly instanciates A, B or C and 
//returns the instance as a Base pointer.
Base * generate(void);

/* 
whats the difference of dynamic_cast with pointers and references in c++?
[pointer] If the cast is not valid, it returns a null pointer when used with pointers. 
[reference] When used with references, it throws an exception (std::bad_cast) if the cast is not valid. 
*/

//It prints the actual type of the object 
//pointed to by p: "A", "B" or "C"
void identify(Base* p);

//It prints the actual type of the object 
//pointed to by p: "A", "B" or "C"
//Using a pointer inside this function is forbidden.
void identify(Base& p);

#endif
