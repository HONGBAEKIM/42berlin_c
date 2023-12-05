/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:01:38 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/05 14:01:41 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
//• The first parameter is the address of an array.
//• The second one is the length of the array.
//• The third one is a function that will be call on every element of the array.
void iter(T *array, unsigned int const length, void (*call)(T &))
{
    for (unsigned int i = 0; i < length; i++)
        call (array[i]);
}

template<typename T>
void addone(T &a)
{
    a++;    
}

template<typename T>
void print(T &a)
{
    std::cout << a << " ";
}

#endif
