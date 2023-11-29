/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:29 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/29 11:13:29 by hongbaki         ###   ########.fr       */
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
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        _grade = grade;

}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    (*this) = src;
}
        
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
        _grade = src._grade;
    return (*this);
}

//Overloading the << operator for the Bureaucrat class
std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
    o << src.getName() << ", grade : " << src.getGrade();
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

