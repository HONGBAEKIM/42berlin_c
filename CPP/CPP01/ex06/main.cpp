/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:57 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/02 21:44:32 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int argc, char **argv) 
{
	Harl harl;

    if (argc != 2)
        std::cout << "command : ./harlFilter [DEBUG, INFO, WARNING or ERROR]" << std::endl;
	else
        harl.harlFilter(argv[1]);
    return (0);
}
