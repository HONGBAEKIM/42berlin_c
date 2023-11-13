/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 15:16:59 by hongbaki         ###   ########.fr       */
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
    this->_Brain = new Brain;
    (*this) = _Dog;
}
        
Dog& Dog::operator=(const Dog &_Dog)
{
    std::cout << "[Dog] Assignment operator" << std::endl;
    if (this != &_Dog)
    {
        this->type = _Dog.type;
        *this->_Brain = *(_Dog._Brain);
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "[Dog] Destructor" << std::endl;
    delete (this->_Brain);
}

void Dog::makeSound() const
{
    std::cout << "[" << this->type << "] woof" << std::endl;
}


void Dog::setIdea(std::string idea, int i)
{
    this->_Brain->setIdea(idea, i);
}

const std::string& Dog::getIdea(int i) const
{
    return (this->_Brain->getIdea(i));
}
