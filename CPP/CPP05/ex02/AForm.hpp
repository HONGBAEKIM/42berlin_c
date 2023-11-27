/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:56:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 11:34:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        int const _gradeSign;
        int const _gradeExec;
        bool    _signed;


    public:
        AForm();
        AForm(std::string const name, int gradeSign, int gradeExec);
        AForm(AForm const &_AForm);
        AForm& operator=(AForm const &_AForm);
        virtual ~AForm();

        std::string const getName() const;
        int getGradeSign() const;
        int getGradeExec() const;
        bool getSigned() const;
        void beSigned(Bureaucrat const &_Bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void    executeCheck(Bureaucrat const & executor) const;

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

        class ExecuteNotSigned : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("Form is not signed!");
                }
        };

        class FileOpeningFail : public std::exception
        {
            public :
                virtual char const *what() const throw()
                {
                    return ("File cannot be opened!");
                }
        };
};

std::ostream &operator<<(std::ostream &o, AForm const &_AForm);

#endif
