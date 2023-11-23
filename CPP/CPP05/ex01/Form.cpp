/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:55:06 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 16:48:43 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradeSign(150), _gradeExec(150), _signed(false)
{

}

Form::~Form()
{

}

Form::Form(std::string const name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &_Form) : _name(_Form._name), _gradeSign(_Form._gradeSign), _gradeExec(_Form._gradeExec)
{
    *this = _Form;
}

Form &Form::operator=(Form const &_Form)
{
    if (this != &_Form)
        _signed = _Form._signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &_Form)
{
    o << "[" << _Form.getName() << "]" << std::endl;
    o << "\t" << "signed : " << _Form.getSigned() << std::endl;
    o << "\t" << "grade needed to sign : " << _Form.getGradeSign() << std::endl;
    o << "\t" << "grade needed to execute : " << _Form.getGradeExec() << std::endl;
    return (o);
}

std::string const Form::getName() const
{
    return (_name);
}

int Form::getGradeSign() const
{
    return (_gradeSign);
}

int Form::getGradeExec() const
{
    return (_gradeExec);
}

bool Form::getSigned() const
{
    return (_signed);
}

void Form::beSigned(Bureaucrat const &_Bureaucrat)
{
    if (_Bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}


