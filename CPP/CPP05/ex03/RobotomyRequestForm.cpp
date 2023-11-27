/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:34 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 15:13:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
    AForm("Robotomy request", 72, 45), _target("Unknown")
{
    
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
    AForm("Robotomy request", 72, 45), _target(target)
{
    
}
        
RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &_Robotomy)
{
    *this = _Robotomy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &_Robotomy)
{
    (void)_Robotomy;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & _Bureaucrat) const
{
    int robotomized;
    
    this->AForm::executeCheck(_Bureaucrat);
    std::cout << "50% chance of ";
    //Generate random integer, calculate the remainder and produce either 0 or 1
    robotomized = rand() % 2;
    if (robotomized)
        std::cout << _target << " was robotomized" << std::endl;
    else
        std::cout << _target << " was not robotomized" << std::endl;
}

