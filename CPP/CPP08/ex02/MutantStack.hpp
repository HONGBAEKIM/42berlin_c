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

# include <stack>
# include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:
    
    public:
        MutantStack();
        virtual ~MutantStack();
        MutantStack(MutantStack<T> const &arr);
        MutantStack<T> &operator=(MutantStack<T> const &rhs);
        
        typedef typename std::stack<T>::container_type container_type;    
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;    
        typedef typename container_type::reverse_iterator reverse_iterator;    
        typedef typename container_type::const_reverse_iterator const_reverse_iterator; 
        
        iterator begin() {return this->c.begin();}  
        iterator end() {return this->c.end();}
        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}
        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
       
};


template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &ms): std::stack<T>(static_cast<std::stack<T> >(ms))
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}


template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
    if (this != &rhs) //Check for self-assignment
        static_cast<std::stack<T> >(*this) = static_cast<std::stack<T> >(rhs);
    return *this; //Return the current object
}

#endif
