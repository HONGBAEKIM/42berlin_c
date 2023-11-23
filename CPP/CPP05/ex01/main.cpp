/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 13:15:48 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void)
{
	Form 		form("formular", 10, 4);
	Bureaucrat	ABCD("ABCD", 11);

	std::cout << form << std::endl;
	std::cout << ABCD << std::endl;
	
	ABCD.signForm(form);
	ABCD.upGrade();
	ABCD.signForm(form);

	std::cout << std::endl << form << std::endl;

	return (0);
}
