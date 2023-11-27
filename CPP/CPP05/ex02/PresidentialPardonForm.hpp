/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:33 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 13:08:42 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string const _target;
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &_Presidential);


    public:
        PresidentialPardonForm(std::string const &target);
        virtual ~PresidentialPardonForm();
        
        PresidentialPardonForm& operator=(PresidentialPardonForm const &_Presidential);

        void execute(Bureaucrat const & _Bureaucrat) const;
        
};

#endif

