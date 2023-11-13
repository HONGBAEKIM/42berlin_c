/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:02 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/13 14:28:38 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
 
class Brain
{
    protected:
        std::string ideas[100];
        
    public:
        Brain(void);
        Brain(const Brain &_Brain);
        Brain& operator=(const Brain &_Brain);
        virtual ~Brain(void);

        std::string getIdea(int i) const;
        void setIdea(std::string idea, int i);
};

#endif
