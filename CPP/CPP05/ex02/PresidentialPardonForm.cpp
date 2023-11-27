/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:31 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 14:54:59 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("Presidential pardon", 25, 5), _target("Unknown")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
    AForm("Presidential pardon", 25, 5), _target(target)
{
    
}
        
PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &_Presidential)
{
    *this = _Presidential;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &_Presidential)
{
    (void)_Presidential;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & _Bureaucrat) const
{
    this->AForm::executeCheck(_Bureaucrat);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
