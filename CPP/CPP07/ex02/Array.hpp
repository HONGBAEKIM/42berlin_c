/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:02:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/08 17:00:51 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//By completing this exercise, 
//you will gain practical experience in 
//implementing class templates, 
//working with dynamic memory, handling exceptions, 
//and designing a class that manages an array of elements. 
//It's a good opportunity to reinforce your understanding of C++ features 
//and best practices.

//Simple type ex
/* int simpleInt = 42;
char simpleChar = 'A';
float simpleFloat = 3.14f; */

//Complex Type Example
/* 
// Array of integers (complex type)
int complexArray[5] = {1, 2, 3, 4, 5};

// Struct representing a point in 2D space (complex type)
struct Point {
    int x;
    int y;
};

Point complexStruct = {10, 20}; */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <stdlib.h>

template<typename T>
class Array
{
    private:
        class OutOfRangeException: public std::exception
        {
            public:
                virtual char const *what() const throw()
                {
                    return ("Array::exception: Index is out of bounds");
                }
        };
        //Data Members
        //Represents the size of the array
        unsigned int const n;
        //Points to a dynamically allocated array of type 'T'
        T *array;
    
    public:
        //Default constructor that creates an empty array with size 0.
        Array();
        
        //Destructor that deallocates the dynamically allocated memory for the array.
        ~Array();
        
        //Parameterized constructor that creates an array of size
        Array(unsigned int arraysize);
        
        //Copy constructor that performs a deep copy of another 
        Array(Array<T> const &arr);
        
        //Overloaded assignment operator that performs a deep copy from another Array object.
        Array<T> &operator=(Array<T> const &rhs);
        
        //Overloaded subscript operator that provides access to elements with bounds checking. 
        //If the index i is out of range, it throws an OutOfRangeException exception.
        T &operator[](unsigned int i);
        
        //Returns the size of the array
        unsigned int size() const;
};

//Data member 'n' represents the size of the array 0 which is empty array
template<typename T>
Array<T>::Array(): n(0)
{
    //Allocates dynamic memory for an array of type T with size 0
    array = new T[0];
}

template<typename T>
Array<T>::~Array()
{
    delete[] array;
}

//This constructor for the Array class template is the parameterized constructor, 
//and it is used to create an array with a specified size. 
template<typename T>
Array<T>::Array(unsigned int arraysize): n(arraysize)
{
    //Allocates dynamic memory for an array of type T with the specified size n
    array = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        //Initializes each element of the array to the default value of type T
        array[i] = T();
    }
}

//The copy constructor creates a new object of the Array class 
//that is a copy of another Array object (arr). 
//The new object has its own dynamic memory allocated,
// and the elements are copied from the source array.
template<typename T>
Array<T>::Array(Array<T> const &arr) : n(arr.size())
{
    array = new T[arr.size()];
    for (size_t i = 0; i < n; i++)
        array[i] = arr.array[i];
}


template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
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
