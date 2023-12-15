/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:13:56 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/13 14:14:00 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <limits>
# include <vector>
# include <algorithm>
# include <exception>

//A Span typically refers to a sequence of elements between two points or indices. 

//std::vector for a dynamic array of elements with fast random access.
//std::multiset for a sorted collection of elements allowing duplicates.
//std::map for associating unique keys with values in a sorted order.
class Span
{
    private:
        //'Span' class cannot be created using the default constructor from outside the class
        Span();
        
        //Maximum size
        unsigned const int n;
        
        //Vector to store integers
        std::vector<int> vec;
        

        class OutOfRangeException: public std::exception
        {
            public:
                virtual char const *what() const throw()
                {
                    return ("Span::exception: Size is out of range");
                }
        };

        class NoSpanException: public std::exception
        {
            public:
                virtual char const *what() const throw()
                {
                    return ("Span::exception: Not enough values for a span");
                }
        };


    public:
        Span(int nb);
        ~Span();
        Span(Span const &s);
        Span &operator=(Span const &rhs);

        //Add a single number to the Span
        void addNumber(int nb);

        //Add a range of numbers to the Span
        void addRange(std::vector<int> v);

        //Find the shortest span between elements
        unsigned int shortestSpan();

        //Find the longest span between elements
        unsigned int longestSpan();
};

#endif
