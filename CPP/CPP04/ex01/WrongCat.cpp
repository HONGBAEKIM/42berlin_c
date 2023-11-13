/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 13:01:59 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "[WrongCat] Default constructor" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &_WrongCat)
{
    std::cout << "[WrongCat] Copy constructor" << std::endl;
    (*this) = _WrongCat;
}
        
WrongCat& WrongCat::operator=(const WrongCat &_WrongCat)
{
    std::cout << "[WrongCat] Assignment operator" << std::endl;
    if (this != &_WrongCat)
        this->_type = _WrongCat._type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "[WrongCat] Destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    //this will not print out
    //because WorngAnimal.hpp does not have a virtual makeSound. 
    std::cout << "[" << this->_type << "] Wrong_ccaatt : meow" << std::endl;
}
