/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:24 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 16:08:11 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"
 
class Brain
{
    protected:
        std::string ideas[100];

    public:
        Brain(void);
        Brain(const Brain &_Brain);
        Brain& operator=(const Brain &_Brain);
        virtual ~Brain(void);

        std::string getIdea(int n) const;
		void setIdea(std::string idea, int n);
};

#endif

