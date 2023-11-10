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
    std::cout << "[" << this->_type << "] Wrong_ccaatt" << std::endl;
}
