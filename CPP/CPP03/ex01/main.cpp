/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:02:16 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 11:50:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) 
{
	ScavTrap aaa("aaa");
	std::cout << '\n';
	ScavTrap bbb( aaa);
	std::cout << '\n';
	ScavTrap ccc("ccc");
	std::cout << '\n';
	aaa.attack("ccc");
	std::cout << '\n';
	ccc.takeDamage(20);
	std::cout << '\n';
	ccc.attack("aaa");
	std::cout << '\n';
	aaa.takeDamage(20);
	std::cout << '\n';
	aaa.beRepaired(100);
	std::cout << '\n';
	aaa.guardGate();
	std::cout << '\n';
	aaa.attack("ccc");
	std::cout << '\n';
	ccc.takeDamage(1000);
	std::cout << '\n';
	ccc.attack("aaa");
	std::cout << '\n';
	return (0);
}
