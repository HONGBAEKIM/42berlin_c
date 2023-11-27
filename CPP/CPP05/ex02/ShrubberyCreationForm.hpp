/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:38 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 15:43:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream> //file stream : enable reading form and writing to files.
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const _target;
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &_Robotomy);

    public:
        ShrubberyCreationForm(std::string const &target);
        virtual ~ShrubberyCreationForm();
        
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &_Robotomy);

        void execute(Bureaucrat const & _Bureaucrat) const;
        
};

#endif
