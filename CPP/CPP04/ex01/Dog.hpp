/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 15:18:32 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
 
class Dog : public Animal
{
    private:
        Brain* _Brain;
    
    public:
        Dog(void);
        Dog(const Dog &_Dog);
        Dog& operator=(const Dog &_Dog);
        ~Dog(void);

        void makeSound() const;
        //const std::string& getIdea(int i) const;
        //void setIdea(std::string idea, int i);
        Brain* getBrain(void) const;
};

#endif
