/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:44:28 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 16:53:29 by hongbaki         ###   ########.fr       */
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

static const std::string  lowerStr(std::string const str)
{
    std::string r;

    for (unsigned int i = 0; i < str.size(); i++)
        r += tolower(str[i]);
    return (r);
}

static AForm *newShrubbery(std::string const target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *newRobotomy(std::string const target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *newPresidential(std::string const target)
{
    return (new PresidentialPardonForm(target));
}


static int  getFormNumber(std::string const formName)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = -1;

    for (int n = 0; n < 3; n++)
    {
        if (lowerStr(formName) == formNames[n])
        {
            i = n;
            break;
        }
    }
    return (i);
}

AForm* Intern::makeForm(std::string const formName, std::string const target) const
{
    constructorPtr funCreation[3] = {&newShrubbery, &newRobotomy, &newPresidential};
    int i;
    AForm *formPtr = NULL;
    
    i = getFormNumber(formName);
    std::cout << "Intern" << std::endl;
    if (i >= 0)
    {
        formPtr = funCreation[i](target);
        std::cout << " creates " << formPtr->getName() << " formular" << std::endl;
    }
    else
        std::cout << " cannot create " << formName << " because " << "it's unknown" << std::endl;
    return (formPtr);
}

//typedef AForm *(*constructorPtr)(const std::string);
// # include "ShrubberyCreationForm.hpp"
// # include "RobotomyRequestForm.hpp"
// # include "PresidentialPardonForm.hpp"
