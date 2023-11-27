/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 18:10:59 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void)
{
	Form 		form("formular", 10, 4);
	Bureaucrat	AAA("AAA", 11);

	std::cout << form << std::endl;
	std::cout << AAA << std::endl;
	
	AAA.signForm(form);
	std::cout << std::endl;
	std::cout << form << std::endl;
	std::cout << AAA << std::endl;

	AAA.upGrade();
	AAA.signForm(form);

	std::cout << std::endl;
	std::cout << form << std::endl;
	std::cout << AAA << std::endl;

	return (0);
}
