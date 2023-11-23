/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 16:42:50 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &_Bureaucrat);
        Bureaucrat& operator=(Bureaucrat const &_Bureaucrat);
        virtual ~Bureaucrat();

        std::string const getName() const;
        int getGrade() const;
        void upGrade();
        void downGrade();
        void signForm(Form &_Form) const;

        class GradeTooHighException : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("Bureaucrat::exception : Grade too high!");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("Bureaucrat::exception : Grade too low!");
                }
        };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &_Bureaucrat);

#endif
