/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:06 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 15:57:57 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>
//std::cout, std::endl
# include <iostream>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        const std::string getType();
        void setType(std::string type);
};

#endif