/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:01:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 10:01:47 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
    public:
        //Default constructor
        ClapTrap(void);
        //Copy constructor
        ClapTrap(const ClapTrap &_ClapTrap);
        //Assignment operator
        ClapTrap& operator=(const ClapTrap &_ClapTrap);
        //Destructor
        ~ClapTrap(void);

        //Constructor for name
        ClapTrap(std::string name);

        std::string getName(void) const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
