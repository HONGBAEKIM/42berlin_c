/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:22:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 10:45:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "dog->getType() : " << dog->getType() << " " << std::endl;
    std::cout << "cat->getType() : " << cat->getType() << " " << std::endl;
    
    animal->makeSound(); 
    dog->makeSound();
    cat->makeSound();
    
    const WrongAnimal* animal2 = new WrongAnimal();
    const WrongAnimal* cat2 = new WrongCat();
    
    std::cout << "cat2->getType() : " << cat2->getType() << " " << std::endl;
    
    animal2->makeSound();
    cat2->makeSound();

    delete animal;
    delete dog;
    delete cat;
    delete animal2;
    delete cat2;  

    return (0);
}

/* int	main(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	
	return (0);
} */
