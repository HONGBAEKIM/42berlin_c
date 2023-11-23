/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 12:56:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat& operator=(Bureaucrat const &src);
        virtual ~Bureaucrat(void);

        std::string const getName() const;
        int getGrade() const;
        void upGrade();
        void downGrade();

        class GradeTooHighException : public std::exception
        {
            public :
                char const *what() const throw()
                {
                    return ("Grade too high!");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :
                char const *what() const throw()
                {
                    return ("Grade too low!");
                }
        };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif
