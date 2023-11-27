/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:44:26 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 16:33:42 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class Intern
{
    
    public:
        Intern();
        Intern(Intern const &_Intern);
        virtual ~Intern();

        Intern& operator=(Intern const &_Intern);
        AForm* makeForm(std::string const formName, std::string const target) const;
        
};

//create type alias.
typedef AForm *(*constructorPtr)(const std::string);

#endif

