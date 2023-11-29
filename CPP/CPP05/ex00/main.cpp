/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:54:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/29 11:14:56 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testBasic(void)
{
	Bureaucrat	ABCD("ABCD", 6);

	// Using the overloaded << operator to print the Bureaucrat object
	std::cout << ABCD << std::endl;
	ABCD.downGrade();
	std::cout << ABCD << std::endl;
	ABCD.upGrade();
	ABCD.upGrade();
	ABCD.upGrade();
	ABCD.upGrade();
	std::cout << ABCD << std::endl;
}

void	testExceptionLow(void)
{
	Bureaucrat	ABCD("ABCD", 151);
}

void	testExceptionHigh(void)
{
	Bureaucrat	ABCD("ABCD", 0);
}

void	testDownGrade(void)
{
	Bureaucrat	ABCD("ABCD", 2);
	std::cout << ABCD << std::endl;
    ABCD.upGrade();
	std::cout << ABCD << std::endl;
	ABCD.upGrade();
	std::cout << ABCD << std::endl;
}

void	testUpGrade(void)
{
	Bureaucrat	ABCD("ABCD", 149);
	std::cout << ABCD << std::endl;
	ABCD.downGrade();
	std::cout << ABCD << std::endl;
	ABCD.downGrade();
	std::cout << ABCD << std::endl;
}

int	main(void)
{
	try
	{
		testBasic();
	}
	catch (std::exception &e)
	{
	    std::cout << "testBasic" << std::endl; //regular informational output
		//e.what(): virtual function in the std::exceptions class
		std::cerr << e.what() << std::endl; //error msg output
	}

	std::cout << std::endl;
	try
	{
		testExceptionLow();
	}
	catch (std::exception &e)
	{
	    std::cout << "testExceptionLow" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionHigh();
	}
	catch (std::exception &e)
	{
	    std::cout << "testExceptionHigh" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		testDownGrade();
	}
	catch (std::exception &e)
	{
	    std::cout << "testDownGrade" << std::endl;
        std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testUpGrade();
	}
	catch (std::exception &e)
	{
	    std::cout << "testUpGrade" << std::endl;
        std::cerr << e.what() << std::endl;
	}

	return (0);
}
