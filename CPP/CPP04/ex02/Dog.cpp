/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 09:48:57 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "[Dog] Default constructor" << std::endl;
    this->type = "Dog";
    this->_Brain = new Brain();
}

Dog::Dog(const Dog &_Dog)
{
    std::cout << "[Dog] Copy constructor" << std::endl;
    this->type = _Dog.type;
    this->_Brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->_Brain->setIdea(_Dog._Brain->getIdea(i), i);
}
        
Dog& Dog::operator=(const Dog &_Dog)
{
    std::cout << "[Dog] Assignment operator" << std::endl;
    if (this != &_Dog)
        this->type = _Dog.type;
    for (int i = 0; i < 100; i++)
        this->_Brain->setIdea(_Dog._Brain->getIdea(i), i);
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "[Dog] Destructor" << std::endl;
    delete this->_Brain;
}

void Dog::makeSound() const
{
    std::cout << "[" << this->type << "] woof" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (this->_Brain);
}
