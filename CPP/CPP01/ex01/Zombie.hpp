/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:17:41 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 14:27:23 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

//std::cout, std::endl
#include <iostream>

class Zombie
{
    
    public:
        Zombie();
        void setName(std::string name);
        void announce(void);
        ~Zombie();
    
    private:
        std::string _name;
    
};

Zombie* zombieHorde(int N, std::string name);

#endif
