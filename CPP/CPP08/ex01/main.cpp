/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:07 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/13 15:14:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}

//Create a 'Span' object with a maximum size of 5
//[3, 6, 9, 11, 17]
//Shortiest span is 2(the difference between 9 and 11)
//Longiest span is 14(the difference between 3 and 17)


/* int	main()
{
	std::cout << "create empty span max size 5\n";
	Span sp = Span(5);
	
	std::cout << "try shortestSpan\n";
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "try longest span\n";
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "insert 7 numbers\n";
	try
	{
		for (int i = 0; i < 7; i++)
		{
			sp.addNumber(i);
		}
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span is: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "create a span with maxsize 12,000; test copy constructor\n";
	std::vector<int> vektor (12000);
	for (unsigned int i = 0;  i < vektor.size(); i++)
		vektor[i] = i;	
	Span bsp(12000);
	Span bigsp(bsp); //copy constructor
	try
	{
		bigsp.addRange(vektor);
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "shortest span is: " << bigsp.shortestSpan() << std::endl;
		std::cout << "longest span is: " << bigsp.longestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
} */
