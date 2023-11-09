/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:02:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 10:02:33 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

//Class FragTrap inherit ClapTrap
class FragTrap : public ClapTrap
{
    private:
        
    public:
        //Default constructor
        FragTrap(void);
        //Copy constructor
        FragTrap(const FragTrap &_FragTrap);
        //Assignment operator
        FragTrap& operator=(const FragTrap &_FragTrap);
        //Destructor
        ~FragTrap(void);

        //Constructor for name
        FragTrap(std::string name);
        
        void highFivesGuys(void);
};

#endif
