/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:27:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 13:54:18 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data	magic_numbers = {42, 24};
	Data *	magic_ptr = &magic_numbers;

	std::cout << "pointer " << magic_ptr << " points to " << magic_ptr->val1 << " and " << magic_ptr->val2 << std::endl;

	//convert a pointer (magic_ptr) into an integer representation (serial)
	uintptr_t	serial = Serializer::serialize(magic_ptr);
	std::cout << "serial is " << serial << std::endl;

	//convert serial back to a pointer. 
	magic_ptr = Serializer::deserialize(serial);
	std::cout << "pointer " << magic_ptr << " points to " << magic_ptr->val1 << " and " << magic_ptr->val2 << std::endl;
}
