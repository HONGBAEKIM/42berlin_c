/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:54:57 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 16:09:20 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


/*

std::vector:

Characteristics:
Dynamic array that automatically resizes itself.
Efficient random access to elements.
Elements are stored in contiguous memory locations.


std::deque (Double-ended Queue):

Characteristics:
Similar to vectors but allows efficient insertion and deletion at both ends.
Implemented as a sequence of individually allocated blocks, 
allowing efficient insertion/removal at the beginning and end.
Usage in the code:


std::list:

Characteristics:
Doubly-linked list, where each element contains a link to the next and previous elements.
Efficient insertion and removal of elements at any position.
No direct access to elements by index; iterators are used to traverse the list.


<<<Differences in Access Time>>>
std::vector provides fast random access to elements 
due to contiguous memory storage.

std::deque also allows random access, 
but it may have slightly slower access times compared to vectors.

std::list does not support direct random access; 
accessing elements requires traversing the list using iterators.


<<<Use Cases>>>

Use std::vector when you need fast random access 
and the size of the container may change frequently.

Use std::deque when you need fast insertion/removal 
at both ends and random access is still required.

Use std::list when you need frequent insertion/removal at any position, 
and random access is not a primary concern.
*/

int main() 
{
    //vector
    std::cout << "Looking for 24 in a 42 vector" << std::endl;
    //Declare a vector of integers named myvector
    std::vector<int> myvector;
    //Fill myvector with 42 copies of the value 42.
    myvector.assign(42, 42);
    //Assign the value 24 to the element at index 24.
    myvector[24] = 24;
    
    std::vector<int>::iterator itv = easyfind(myvector, 24);
    if (itv != myvector.end())
        std::cout << "found value " << *itv << std::endl;
    else
        std::cout << "not found value" << std::endl;
    
    std::cout << "Looking for unexisting 1 in a 42 vector" << std::endl;
    itv = easyfind(myvector, 1);
    if (itv != myvector.end())
        std::cout << "found value " << *itv << std::endl;
    else
        std::cout << "not found value" << std::endl;
    std::cout << std::endl;


    //deque
    std::cout << "Looking for 24 in a 42 deque" << std::endl;
    //Declare a deque of integers named mydeque
    std::deque<int> mydeque;
    //Fill mydeque with 42 copies of the value 42.
    mydeque.assign(42, 42);
    //Assign the value 24 to the element at index 24.
    mydeque[24] = 24;
    
    std::deque<int>::iterator itd = easyfind(mydeque, 24);
    if (itd != mydeque.end())
        std::cout << "found value " << *itd << std::endl;
    else
        std::cout << "not found value" << std::endl;
    
    std::cout << "Looking for unexisting 1 in a 42 deque" << std::endl;
    itd = easyfind(mydeque, 1);
    if (itd != mydeque.end())
        std::cout << "found value " << *itd << std::endl;
    else
        std::cout << "not found value" << std::endl;
    std::cout << std::endl;
    

    //list
    std::cout << "Looking for 24 in a 42 list" << std::endl;
    //Declare a list of integers named mylist
    std::list<int> mylist;
    //mylist to be filled with 42 copies of the value 42
    mylist.assign(42, 42);
    //it is setting the value of the first element of the list to 24.
    mylist.front() = 24;
    
    std::list<int>::iterator itl = easyfind(mylist, 24);
    if (itl != mylist.end())
        std::cout << "found value " << *itl << std::endl;
    else
        std::cout << "not found value" << std::endl;
    
    std::cout << "Looking for unexisting 1 in a 42 list" << std::endl;
    itl = easyfind(mylist, 1);
    if (itl != mylist.end())
        std::cout << "found value " << *itl << std::endl;
    else
        std::cout << "not found value" << std::endl;
    

    return (0);
}
