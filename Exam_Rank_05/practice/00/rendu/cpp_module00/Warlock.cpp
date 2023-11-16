/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:16:28 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/14 15:48:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title)
{
    this->_name = _name;
    this->_title = _title;
    std::cout << _name << ": This looks like another boring day.\n";
}


Warlock& Warlock::operator=(Warlock const &_Warlock)
{
    this->_name = _Warlock._name;
    this->_title = _Warlock._title;
    return *this;
}

Warlock::~Warlock(void)
{
    std::cout << _name << ": My job here is done!\n";
}

Warlock::Warlock(Warlock const &_Warlock)
{
    *this = _Warlock;
}

std::string const &Warlock::getName(void) const
{
    return (this->_name);
}

std::string const &Warlock::getTitle(void) const
{
    return (this->_title);
}

void Warlock::setTitle(std::string const &title)
{
    this->_title = title;
}

void Warlock::introduce(void) const
{
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}
