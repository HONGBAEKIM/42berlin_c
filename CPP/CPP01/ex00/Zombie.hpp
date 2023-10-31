/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:17:41 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/31 20:51:28 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

//std::cout, std::endl
#include <iostream>

class Zombie
{
    public:
        Zombie(std::string name);
        void announce(void);
        ~Zombie();
    
    private:
        std::string _name;
    
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif
