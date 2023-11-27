/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:56:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 13:16:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeSign(150), _gradeExec(150), _signed(false)
{
}

AForm::~AForm()
{
}

AForm::AForm(std::string const name, int gradeSign, int gradeExec) 
    : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &_AForm) 
    : _name(_AForm._name), _gradeSign(_AForm._gradeSign), _gradeExec(_AForm._gradeExec)
{
    *this = _AForm;
}

AForm &AForm::operator=(AForm const &_AForm)
{
    if (this != &_AForm)
        _signed = _AForm._signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm const &_AForm)
{
    o << "[" << _AForm.getName() << "]" << std::endl;
    o << "\t" << "signed : " << _AForm.getSigned() << std::endl;
    o << "\t" << "grade needed to sign : " << _AForm.getGradeSign() << std::endl;
    o << "\t" << "grade needed to execute : " << _AForm.getGradeExec() << std::endl;
    return (o);
}

std::string const AForm::getName() const
{
    return (_name);
}

int AForm::getGradeSign() const
{
    return (_gradeSign);
}

int AForm::getGradeExec() const
{
    return (_gradeExec);
}

bool AForm::getSigned() const
{
    return (_signed);
}

void AForm::beSigned(Bureaucrat const &_Bureaucrat)
{
    if (_Bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::executeCheck(Bureaucrat const &_Bureaucrat) const
{
    if (!this->getSigned())
        throw AForm::ExecuteNotSigned();
    if (this->getGradeExec() < _Bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
}
