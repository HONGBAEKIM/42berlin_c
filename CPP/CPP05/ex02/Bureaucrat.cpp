/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:29 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 11:34:23 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;

}

Bureaucrat::Bureaucrat(Bureaucrat const &_Bureaucrat)
{
    (*this) = _Bureaucrat;
}



Bureaucrat &Bureaucrat::operator=(Bureaucrat const &_Bureaucrat)
{
    if (this != &_Bureaucrat)
        _grade = _Bureaucrat._grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &_Bureaucrat)
{
    o << _Bureaucrat.getName() << ", grade : " << _Bureaucrat.getGrade();
    return (o);
}

std::string const Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::upGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::downGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &_AForm) const
{
    try
    {
        _AForm.beSigned(*this);
        std::cout << _name << " signs " << _AForm.getName() << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cout << _name << " could not sign " << _AForm.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cout << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
}



