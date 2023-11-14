/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:16 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 09:48:33 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "[Brain] Default constructor" << std::endl;
}

Brain::Brain(const Brain &_Brain)
{
    std::cout << "[Brain] Copy constructor" << std::endl;
    (*this) = _Brain;
}
        
Brain& Brain::operator=(const Brain &_Brain)
{
    std::cout << "[Brain] Assignment operator" << std::endl;
    if (this != &_Brain)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = _Brain.ideas[i];
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "[Brain] Destructor" << std::endl;
}

std::string Brain::getIdea(int n) const
{
	if (n >= 0 && n <= 99)
		return (this->ideas[n]);
	else	
		return("Number is out of the range");
}

void Brain::setIdea(std::string idea, int n)
{
	if (n >= 0 && n <= 99)
		this->ideas[n] = idea;
	else
		std::cout << "Number is out of the range" << std::endl;
}

