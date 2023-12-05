/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:17:43 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 13:49:46 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

/* Serializer::Serializer(Serializer const &src)
{
    (*this) = src;
}
        
Serializer &Serializer::operator=(Serializer const &src)
{
    (void) src;
    return (*this);
} */

Serializer::Serializer(Serializer const &src)
{
   static_cast<void>(src);
}
        
Serializer &Serializer::operator=(Serializer const &src)
{
    static_cast<void>(src);
    return (*this);
}


uintptr_t Serializer::serialize(Data* ptr)
{
    //convert (Data *ptr) to integer type (uintptr_t)
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    //convert (uintptr_t ra) integer back to a pointer type (Data *)
    // it is reverse of serialization.
    return reinterpret_cast<Data *>(raw);
} 


