/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:01:59 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 10:37:43 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) 
{
    ClapTrap aaa("aaa");
	ClapTrap bbb("bbb");
	std::cout << '\n';
	aaa.beRepaired(3);
	std::cout << '\n';
	aaa.attack("bbb");
	std::cout << '\n';
	bbb.takeDamage(4);
	std::cout << '\n';
	aaa.attack("bbb");
	std::cout << '\n';
	bbb.takeDamage(6);
	std::cout << '\n';
	bbb.attack("aaa");
	std::cout << '\n';
	aaa.takeDamage(0);
	std::cout << '\n';
	aaa.attack("bbb");
	std::cout << '\n';
	bbb.takeDamage(4);
	std::cout << '\n';
	return (0);
}
