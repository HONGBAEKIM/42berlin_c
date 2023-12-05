/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:56:12 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/05 14:17:34 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

// templates are used to create generic classes and functions 
// that can work with different data types ( such as int, float and double).

/* 
Benefits of Generic Classes:

Code Reusability: Write code that works for multiple data types without duplicating logic.
Type Safety: The compiler enforces type correctness, preventing type-related errors at compile-time.
Flexibility: Users can use the same generic class with different data types, making the code more versatile.
Abstraction: Generic classes abstract away the details of the specific data type, promoting cleaner and more abstract code. 
*/
template<typename T> void swap(T &a, T &b);
template<typename T> T const &min(T const &a, T const &b);
template<typename T> T const &max(T const &a, T const &b);

template<typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T const &min(T const &a, T const &b)
{
    return (a < b) ? a : b;
}

template<typename T>
T const &max(T const &a, T const &b)
{
    return (a > b) ? a : b;
}

#endif
