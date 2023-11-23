/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 13:28:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "[Animal] Default constructor" << std::endl;
    //initialize type of an Animal object within the constructor or other member functions.
    this->type = "Animal";
}

Animal::Animal(const Animal &_Animal)
{
    std::cout << "[Animal] Copy constructor" << std::endl;
    (*this) = _Animal;
}
        
Animal& Animal::operator=(const Animal &_Animal)
{
    std::cout << "[Animal] Assignment operator" << std::endl;
    if (this != &_Animal)
        this->type = _Animal.type;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "[Animal] Destructor" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "[" << this->type << "] does not make sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
