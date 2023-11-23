/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:22:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/09 13:48:30 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << << std::endl;
    
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
    
    const WrongAnimal* animal2 = new WrongAnimal();
    const WrongAnimal* cat2 = new WrongCat();
    
    std::cout << cat2->getType() << " " << std::endl;
    
    cat2->makeSound();
    animal2->makeSound();
    std::cout << std::endl;

    delete animal;
    delete dog;
    delete cat;
    delete animal2;
    delete cat2;
    
    return (0);
}