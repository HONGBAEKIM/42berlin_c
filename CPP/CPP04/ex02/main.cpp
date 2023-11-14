/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:22:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 10:39:47 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/* int	main(void)
{
	Dog _Dog;
	Cat _Cat;

	_Dog.makeSound();
	_Cat.makeSound();
	
	return (0);
} */

int	main(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	
	return (0);
}
