/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/27 15:16:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime> //std::time() 
# include <cstdlib> //rand()
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string const _target;
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &_Robotomy);

    public:
        RobotomyRequestForm(std::string const &target);
        virtual ~RobotomyRequestForm();
        
        RobotomyRequestForm& operator=(RobotomyRequestForm const &_Robotomy);

        void execute(Bureaucrat const & _Bureaucrat) const;
        
};

#endif
