/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:02:25 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

//A template in C++ is a mechanism for creating generic classes or functions. 

//A container in C++ refers to a class template or a data structure that can store 
//and organize multiple elements of the same or different types. 

# include <iostream>

# include <stack>
//deque is container which is data structure (double-ended queue)
# include <deque>

template<typename T>
//MutantStack inherits std::stack<T>
class MutantStack : public std::stack<T>
{
    private:
    
    public:
        MutantStack();
        virtual ~MutantStack();
        MutantStack(MutantStack<T> const &arr);
        MutantStack<T> &operator=(MutantStack<T> const &rhs);
        
        //'std::stack<T>::container_type' is dependent name
        //it depends on the templete parameter <T>
        typedef typename std::stack<T>::container_type container_type;
        
        //You can use it to read and write (modify) the values in the iterator
        typedef typename container_type::iterator iterator;
        //You can use it to read values from the const_iterator but cannot modify the values.
        typedef typename container_type::const_iterator const_iterator;    
        typedef typename container_type::reverse_iterator reverse_iterator;    
        typedef typename container_type::const_reverse_iterator const_reverse_iterator; 
        
        /*
        begin(): Returns an iterator pointing to the first element of the container.
        end(): Returns an iterator pointing one past the last element of the container.
        rbegin(): Returns a reverse iterator pointing to the last element of the container.
        rend(): Returns a reverse iterator pointing to one position before the first element of the container.
        */
        //'this->c' accesses the 'c' member of the current instance
        iterator begin() {return this->c.begin();}  
        iterator end() {return this->c.end();}
        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}
        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
};

//when you create an instance of MutantStack<T>, 
//the constructor initializes the std::stack<T> base class part 
//using its default constructor.
template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
}

//copy constructor
//the copy constructor of MutantStack<T> is constructing 
//a new instance by copying another MutantStack<T> (ms). 
//During this process, it ensures that the base class part (std::stack<T>) 
//is correctly constructed using the copy constructor of std::stack<T>. 
//The const & ensures that the original ms object is not modified during this copy process.
template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &ms): std::stack<T>(static_cast<std::stack<T> >(ms))
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

//copy assignment operator
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
    if (this != &rhs) //Check for self-assignment
    {
        //Assigns the contents of rhs to the current object. 
        //This involves using the copy assignment operator of std::stack<T>
        static_cast<std::stack<T> >(*this) = static_cast<std::stack<T> >(rhs);
    }
    return *this; //Return the current object
}

#endif
