/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:01:38 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/08 16:27:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/*
Template Parameters:

typename T: Represents the type of the array elements.
typename Func: Represents the type of the function to be applied to each element.
Function Parameters:

T array[]: An array of type T.
size_t size: The size of the array.
Func function: A function of type Func that will be applied to each element.
*/

template<typename T, typename Func>
void iter(T array[], size_t size, Func function)
{
    for (size_t i = 0; i < size; i++)
        function(array[i]);
}

template<typename T>
void ft_print(const T &a)
{
    std::cout << a << " ";
}

#endif

