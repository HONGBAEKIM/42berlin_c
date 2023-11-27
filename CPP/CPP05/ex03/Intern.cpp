/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:44:28 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 16:38:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern()
{
    
}
        
Intern::~Intern()
{

}

Intern::Intern(Intern const &_Intern)
{
    *this = _Intern;
}

Intern &Intern::operator=(Intern const &_Intern)
{
    (void)_Intern;
    return (*this);
}

void Intern::execute(Bureaucrat const & _Bureaucrat) const
{
    this->AForm::executeCheck(_Bureaucrat);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
