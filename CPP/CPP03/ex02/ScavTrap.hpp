/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:02:23 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 10:02:24 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//Class ScavTrap inherit ClapTrap
class ScavTrap : public ClapTrap
{
    private:
        
    public:
        //Default constructor
        ScavTrap(void);
        //Copy constructor
        ScavTrap(const ScavTrap &_ScavTrap);
        //Assignment operator
        ScavTrap& operator=(const ScavTrap &_ScavTrap);
        //Destructor
        ~ScavTrap(void);

        //Constructor for name
        ScavTrap(std::string name);
        
        void attack(const std::string& target);
        void guardGate(void);
};

#endif
