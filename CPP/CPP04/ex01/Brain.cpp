/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:59:59 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 15:20:07 by hongbaki         ###   ########.fr       */
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
        for (int i = 0; i < 100; i++)
            this->setIdea(_Brain.getIdea(i), i);
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "[Brain] Destructor" << std::endl;
}

std::string Brain::getIdea(int i) const
{
    if (0 <= i && i <= 99)
        return (this->ideas[i]);
    else
    {
        std::cout << "Input number is out of range" << std::endl;
        EXIT_FAILURE; 
    }
}
        
        
void Brain::setIdea(std::string idea, int i)
{
    if (0 <= i && i <= 99)
        this->ideas[i] = idea;
    else
    {
        std::cout << "Input number is out of range" << std::endl;
        EXIT_FAILURE;
    }
}
