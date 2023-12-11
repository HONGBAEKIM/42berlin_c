/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:02:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/11 17:27:04 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//By completing this exercise, 
//you will gain practical experience in 
//implementing class templates, 
//working with dynamic memory, handling exceptions, 
//and designing a class that manages an array of elements. 
//It's a good opportunity to reinforce your understanding of C++ features 
//and best practices.

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <stdlib.h>

template<typename T>
class MutantStack
{
    private:
    
    
    public:
        MutantStack();
        virtual ~MutantStack();
        MutantStack(MutantStack<T> const &arr);
        MutantStack<T> &operator=(MutantStack<T> const &rhs);
        
        
        
        
};

//Data member 'n' represents the size of the array 0 which is empty array
template<typename T>
MutantStack<T>::MutantStack(): n(0)
{
    //Allocates dynamic memory for an array of type T with size 0
    array = new T[0];
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    delete[] array;
}

//This constructor for the Array class template is the parameterized constructor, 
//and it is used to create an array with a specified size. 
template<typename T>
MutantStack<T>::MutantStack(unsigned int arraysize): n(arraysize)
{
    //Allocates dynamic memory for an array of type T with the specified size n
    MutantStack = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        //Initializes each element of the array to the default value of type T
        MutantStack[i] = T();
    }
}

//The copy constructor creates a new object of the Array class 
//that is a copy of another Array object (arr). 
//The new object has its own dynamic memory allocated,
// and the elements are copied from the source array.
template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &arr) : n(arr.size())
{
    MutantStack = new T[arr.size()];
    for (size_t i = 0; i < n; i++)
        MutantStack[i] = arr.MutantStack[i];
}


template<typename T>
MutantStack<T> &MutantStack<T>::operator=(Array<T> const &rhs)
{
    if (this != &rhs) //Check for self-assignment
    {
        if (array)
            delete[] array; // Deallocate existing memory
        array = new T[rhs.size()]; // Allocate new memory
        n = rhs.size(); // Update size
        for (unsigned int i = 0; i < n; i++)
            array[i] = rhs[i]; // Copy elements
    }
    return *this; //Return the current object
}

//[] operator overload for your Array class.
template<typename T>
T &Array<T>::operator[](unsigned int i)
{
    //If the index is out of bounds, an OutOfRangeException exception is thrown. 
    if (i >= n)
        throw(OutOfRangeException());
    //If the index is within bounds, 
    //the method returns a reference to the element at the specified index in the array.
    return array[i];
}

//Number of elements dynamic array managed by Array class.
template<typename T>
unsigned int Array<T>::size() const
{
    return n;
}

#endif
