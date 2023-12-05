/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:27:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 15:33:22 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	//The srand() function is called with a specific seed value. 
	//The seed can be any unsigned integer, and it determines the initial state of the random number generator.
	std::srand(std::time(0));
	for (int i = 0; i < 5; i++)
	{
		Base * p = generate();
		//pointer
		identify(p);
		//reference
		identify(*p);
		std::cout << std::endl;
		delete (p);
	}
	return (0);
}
