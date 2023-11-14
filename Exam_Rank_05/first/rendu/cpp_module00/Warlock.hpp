/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:16:34 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 15:48:04 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        Warlock(void);
        Warlock(Warlock const &_Warlock);
        Warlock& operator=(Warlock const &_Warlock);
        
    public:
        Warlock(std::string const &_name, std::string const &_title);
        ~Warlock(void);
        
        std::string const &getName(void) const;
        std::string const &getTitle(void) const;
        
        void setTitle(std::string const &title);
        void introduce(void) const;
        
};

#endif
