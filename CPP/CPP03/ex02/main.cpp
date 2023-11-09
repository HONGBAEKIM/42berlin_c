/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:02:34 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 11:51:15 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

int main( void ) 
{
	FragTrap aaa("aaa");
	std::cout << '\n';
	FragTrap bbb(aaa);
	std::cout << '\n';
	FragTrap ccc("ccc");
	std::cout << '\n';
	aaa.attack("ccc");
	std::cout << '\n';
	ccc.takeDamage(30);
	std::cout << '\n';
	ccc.beRepaired(30);
	std::cout << '\n';
	ccc.attack("aaa");
	std::cout << '\n';
	aaa.takeDamage(1000);
	std::cout << '\n';
	aaa.beRepaired(2);
	std::cout << '\n';
	aaa.highFivesGuys();
	std::cout << '\n';
	return (0);
}
