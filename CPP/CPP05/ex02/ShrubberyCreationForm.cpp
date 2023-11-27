/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:37 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 15:42:04 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm("Shrubbery creation", 145, 137), _target("Unknown")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
    AForm("Shrubbery creation", 145, 137), _target(target)
{
    
}
        
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &_Shrubbery)
{
    *this = _Shrubbery;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &_Shrubbery)
{
    (void)_Shrubbery;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & _Bureaucrat) const
{
    std::ofstream   file;
    
    this->AForm::executeCheck(_Bureaucrat);
    file.open((_target + "_Shrubbery").c_str());
    if (!file.good())
        throw FileOpeningFail();
    file << _target << std::endl;
    file << "is" << std::endl;
    file << "here" << std::endl;
	file.close();
}

