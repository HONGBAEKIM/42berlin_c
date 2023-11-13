/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 10:38:56 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
 
class WrongCat : public WrongAnimal
{
    private:
        
    public:
        WrongCat(void);
        WrongCat(const WrongCat &_WrongCat);
        WrongCat& operator=(const WrongCat &_WrongCat);
        ~WrongCat(void);

        void makeSound() const;
};

#endif
