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

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "[Dog] Default constructor" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &_Dog)
{
    std::cout << "[Dog] Copy constructor" << std::endl;
    (*this) = _Dog;
}
        
Dog& Dog::operator=(const Dog &_Dog)
{
    std::cout << "[Dog] Assignment operator" << std::endl;
    if (this != &_Dog)
        this->type = _Dog.type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "[Dog] Destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[" << this->type << "] ddoogg" << std::endl;
}
