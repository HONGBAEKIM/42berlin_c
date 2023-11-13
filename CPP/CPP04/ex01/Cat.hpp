/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 14:26:11 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
 
class Cat : public Animal
{
    private:
        
    public:
        Cat(void);
        Cat(const Cat &_Cat);
        Cat& operator=(const Cat &_Cat);
        ~Cat(void);

        void makeSound() const;
};

#endif
