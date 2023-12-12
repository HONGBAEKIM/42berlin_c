/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:54:57 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:35 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	//Creates an instance of MutantStack<int>
	//it's initializing the 'std::stack' part of the 'MutantStack' using its default constructor.
	MutantStack<int> mstack;

	//Push: This operation adds an element to the top of the stack.
	//Pop: This operation removes the element from the top of the stack.
	mstack.push(0);
	mstack.push(1);

	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	std::cout << "mstack.size() : " << mstack.size() << std::endl;

	mstack.pop();
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	std::cout << "mstack.size() : " << mstack.size() << std::endl;

	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	//[...]
	mstack.push(5);

	//The begin() function returns an iterator pointing 
	//to the first element of the container.
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		//Print the current element pointed to by the iterator
		std::cout << "*it : " << *it << std::endl;
		++it;
	}


	//s is a new stack that is created and initialized with the contents of mstack. 
	//The elements from mstack are copied into the new stack s
	//you can create a standard stack (std::stack) 
	//using your custom container mstack
	std::stack<int> s(mstack);

	return 0;
}

