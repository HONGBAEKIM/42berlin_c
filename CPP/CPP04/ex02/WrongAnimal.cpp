/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 13:28:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "[WrongAnimal] Default constructor" << std::endl;
    this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &_WrongAnimal)
{
    std::cout << "[WrongAnimal] Copy constructor" << std::endl;
    (*this) = _WrongAnimal;
}
        
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &_WrongAnimal)
{
    std::cout << "[WrongAnimal] Assignment operator" << std::endl;
    if (this != &_WrongAnimal)
        this->_type = _WrongAnimal._type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "[WrongAnimal] Destructor for " << this->_type << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "[" << this->_type << "] does not make sound too" << std::endl;
}
