/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:17:37 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 13:53:20 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream> //input, output streams.
#include <stdint.h> //uintptr_t

struct Data
{
    int val1;
    int val2;
};

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &src);
        ~Serializer();
        Serializer& operator=(Serializer const &src);

    public:
        //It takes a pointer and converts it to the unsigned integer type uintptr_t
        static uintptr_t serialize(Data* ptr);
        //It takes an unsigned integer parameter and converts it to a pointer to Data
        static Data* deserialize(uintptr_t raw);
};

#endif
