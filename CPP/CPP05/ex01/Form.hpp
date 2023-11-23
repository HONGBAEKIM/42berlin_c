/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:55:08 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 16:27:15 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        int const _gradeSign;
        int const _gradeExec;
        bool    _signed;


    public:
        Form();
        Form(std::string const name, int gradeSign, int gradeExec);
        Form(Form const &_Form);
        Form& operator=(Form const &_Form);
        virtual ~Form();

        std::string const getName() const;
        int getGradeSign() const;
        int getGradeExec() const;
        bool getSigned() const;
        void beSigned(Bureaucrat const &_Bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("Grade too high!");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("Grade too low!");
                }
        };
};

std::ostream &operator<<(std::ostream &o, Form const &_Form);

#endif
