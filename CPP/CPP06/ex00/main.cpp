/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:27:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/01 13:52:26 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try 
		{
			ScalarConverter::convert(argv[1]);
		} 
		catch (const std::exception &e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
