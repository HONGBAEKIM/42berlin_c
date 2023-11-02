/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:21:30 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 16:13:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *_weapon;
        std::string _name;
    public:
        HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
        ~HumanB();
};

#endif