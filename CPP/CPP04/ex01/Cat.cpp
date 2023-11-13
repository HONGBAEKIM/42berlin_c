/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 13:28:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "[Cat] Default constructor" << std::endl;
    this->type = "Cat";
    this->_Brain = new Brain();
    return ;
}

Cat::Cat(const Cat &_Cat)
{
    std::cout << "[Cat] Copy constructor" << std::endl;
    this->type = _Cat.type;
    this->_Brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->_Brain->setIdea(_Cat._Brain->getIdea(i), i);
    return ;
}
        
Cat& Cat::operator=(const Cat &_Cat)
{
    std::cout << "[Cat] Assignment operator" << std::endl;
    if (this != &_Cat)
        this->type = _Cat.type;
    for (int i = 0; i < 100; i++)
        this->_Brain->setIdea(_Cat._Brain->getIdea(i), i);
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "[Cat] Destructor" << std::endl;
    delete this->_Brain;
    return ;
}

void Cat::makeSound() const
{
    std::cout << "[" << this->type << "] meow" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return (this->_Brain);
}
