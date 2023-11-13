/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:22:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 17:12:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	//Create Dog, Cat classes
	Animal	*animals[2];
	
	//Store them in the animal array
	for (int i = 0; i < 2; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "--------------" << std::endl;
	for (int i = 0; i < 2; i++)
		delete animals[i];
	std::cout << "--------------" << std::endl;



	Dog	*dog1 = new Dog;
	Dog	*dog2 = new Dog;

	dog1->getBrain()->setIdea("new idea! ", 0);
	std::cout << "--------------" << std::endl;
	*dog2 = *dog1;
	std::cout << "--------------" << std::endl;
	std::cout << dog1->getBrain()->getIdea(0) << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "--------------" << std::endl;
	delete dog1;
	std::cout << "--------------" << std::endl;
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "--------------" << std::endl;
	delete dog2;
	std::cout << "--------------" << std::endl;


	Cat	*cat1 = new Cat;
	Cat	*cat2 = new Cat;

	cat1->getBrain()->setIdea("new idea! ", 0);
	std::cout << "--------------" << std::endl;
	*cat2 = *cat1;
	std::cout << "--------------" << std::endl;
	std::cout << cat1->getBrain()->getIdea(0) << cat2->getBrain()->getIdea(0) << std::endl;
	cat2->getBrain()->setIdea("No idea! ", 0);	
	std::cout << "--------------" << std::endl;
	std::cout << cat1->getBrain()->getIdea(0) << cat2->getBrain()->getIdea(0) << std::endl;
	std::cout << "--------------" << std::endl;
	delete cat1;
	delete cat2;
	
	return (0);
}
