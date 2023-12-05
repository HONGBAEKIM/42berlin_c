/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:04:38 by hongbaki          #+#    #+#             */
/*   Updated: 2023/12/04 15:43:01 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    
}

Base * generate(void)
{
    Base* p;
    //Random()
    int i = std::rand();;
    if (i % 3 == 0)
    {
        p = new A();
        std::cout << "generated and A" << std::endl;   
    }
    else if (i % 3 == 1)
    {
        p = new B();
        std::cout << "generated and B" << std::endl;   
    }
    else
    {
        p = new C();
        std::cout << "generated and C" << std::endl;   
    }
    return (p);
}


void identify(Base* p)
{
    //The 'dynamic_cast' operator is used for safe runtime type checking.
    A* pa = dynamic_cast<A*>(p);
    B* pb = dynamic_cast<B*>(p);
    C* pc = dynamic_cast<C*>(p);
    if (pa != NULL)
        std::cout << p << " is a A pointer" << std::endl;
    else if (pb != NULL)
        std::cout << p << " is a B pointer" << std::endl;
    else if (pc != NULL)
        std::cout << p << " is a C pointer" << std::endl;
    else
        std::cout << p << "ERROR" << std::endl;
}


void identify(Base& p)
{
    bool ok = false;
    try
    {
        //dynamically cast pointer (p) to a reference of type <A&>
        //if the cast is successful, 'ra' will be a reference to the object pointed to by 'p'
        A& ra = dynamic_cast<A&>(p);
        ok = true;
        std::cout << &ra << " is a A reference" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B& rb = dynamic_cast<B&>(p);
        ok = true;
        std::cout << &rb << " is a B reference" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C& rc = dynamic_cast<C&>(p);
        ok = true;
        std::cout << &rc << " is a C reference" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    if (!ok)
        std::cout << "ERROR" << std::endl;
    
}


